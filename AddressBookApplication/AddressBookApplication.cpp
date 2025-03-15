#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>
#include <algorithm>
#include <json/json.h>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void publish(const std::string& message) = 0;
};

class Observable {
public:
    void addToSubscribtion(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
    }

    void publishAll(const std::string& message) {
        for (const auto& observer : observers) {
            observer->publish(message);
        }
    }

private:
    std::vector<std::shared_ptr<IObserver>> observers;
};

class Person {
public:
    Person(const std::string& name, const std::string& phone)
        : name(name), phone(phone) {
    }

    virtual ~Person() = default;

    virtual std::string toString() const = 0;

    //TODO: move to Serializer
    virtual std::string serialize() const = 0;

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }

protected:
    std::string name;
    std::string phone;
};

class Student : public Person {
public:
    Student(const std::string& name, const std::string& phone, const std::string& details)
        : Person(name, phone), details(details) {
    }

    std::string toString() const override {
        return "Student: " + name + ", Phone: " + phone + ", Details: " + details + '\n';
    }

    //TODO: move to Serializer
    std::string serialize() const override {
        return "Student " + name + " " + phone + " " + details + "\n";
    }

private:
    std::string details;
};

class Teacher : public Person {
public:
    Teacher(const std::string& name, const std::string& phone, const std::string& subject)
        : Person(name, phone), subject(subject) {
    }

    std::string toString() const override {
        return "Teacher: " + name + ", Phone: " + phone + ", Subject: " + subject + "\n";
    }

    //TODO: move to Serializer
    std::string serialize() const override {
        return "Teacher " + name + " " + phone + " " + subject +"\n";
    }

private:
    std::string subject;
};

class IViewStrategy {
public:
    virtual ~IViewStrategy() = default;
    virtual void toString(const Person& person) const = 0;
};

class StudentViewStrategy : public IViewStrategy {
public:
    void toString(const Person& person) const override {
        std::cout << "Student: " << person.getName() << ", Phone: " << person.getPhone() << std::endl;
    }
};

class TeacherViewStrategy : public IViewStrategy {
public:
    void toString(const Person& person) const override {
        std::cout << "Teacher: " << person.getName() << ", Phone: " << person.getPhone() << std::endl;
    }
};

class IPersonBuilder {
public:
    virtual ~IPersonBuilder() = default;
    virtual void setName(const std::string& name) = 0;
    virtual void setPhone(const std::string& phone) = 0;
    virtual std::shared_ptr<Person> build() = 0;
};

class StudentBuilder : public IPersonBuilder {
public:
    void setName(const std::string& name) override {
        this->name = name;
    }

    void setPhone(const std::string& phone) override {
        this->phone = phone;
    }

    std::shared_ptr<Person> build() override {
        return std::make_shared<Student>(name, phone, details);
    }

    void setDetails(const std::string& details) {
        this->details = details;
    }

private:
    std::string name;
    std::string phone;
    std::string details;
};

class PersonFactory {
public:
    enum class PersonType { Student, Teacher };

    static std::shared_ptr<Person> createPerson(PersonType type, const std::string& name, const std::string& phone) {
        switch (type) {
        case PersonType::Student: return std::make_shared<Student>(name, phone, "IT");
        case PersonType::Teacher: return std::make_shared<Teacher>(name, phone, "Math");
        default: return nullptr;
        }
    }
};

class ObservablePersonRepository: public Observable {
public:
    virtual ~ObservablePersonRepository() = default;
    virtual void add(std::shared_ptr<Person> person) = 0;
    virtual std::vector<std::string> findAllCached() const = 0;
    virtual void persist(const std::string& collection) const = 0;
};

class JsonSerializerDeserializer {
public:
    JsonSerializerDeserializer() {};

    template<typename T>
    Json::Value toJson(const T& object) {
        Json::Value data;

        constexpr auto nbProperties = std::tuple_size<decltype(T::properties)>::value;

        for_sequence(std::make_index_sequence<nbProperties>{}, [&](auto i) {
            constexpr auto property = std::get<i>(T::properties);
            data[property.name] = object.*(property.member);
        });

        return data;
    }

    template<typename T>
    T fromJson(const Json::Value& data) {
        T object;

        constexpr auto nbProperties = std::tuple_size<decltype(T::properties)>::value;

        for_sequence(std::make_index_sequence<nbProperties>{}, [&](auto i) {
            constexpr auto property = std::get<i>(T::properties);

            using Type = typename decltype(property)::Type;

            //TODO: fix deserialization
            /*object.*(property.member) = 
                Json::asAny<Type>(data[property.name]);*/

        });

        return object;
    }
};

class FilePersonRepository : public ObservablePersonRepository {
public:
    FilePersonRepository() {};

    void add(std::shared_ptr<Person> person) {
        persons.push_back(person);
        publishAll("Person added: " + person->getName());
    }

    std::vector<std::string> findAllCached() const {
        std::vector<std::string> toStringPersons;
        
        for (const auto& person : persons) {
            toStringPersons.push_back(person->toString());
        }
        return toStringPersons;
    }

    void persist(const std::string& collection) const {
        std::ofstream out(collection);
        if (out.is_open()) {
            for (const auto& person : persons) {
                //TODO: use Serializer
                out << person->serialize();
            }
            out.close();
        }
    }

private:
    std::vector<std::shared_ptr<Person>> persons;
};

class PersonView : public IObserver {
public:
    PersonView() {}

    void publish(const std::string& message) override {
        std::cout << "[Notification] " << message << std::endl;
    }

    void displayMenu() const {
        std::cout << "1. Add Student\n2. Add Teacher\n3. Display cached\n4. Persist\n5. Exit\n";
    }

    std::string getInput(const std::string& prompt) const {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }
};

class PersonController {
public:
    PersonController(PersonView& view, ObservablePersonRepository& repository) : view(view), repository(repository) {
        repository.addToSubscribtion(std::make_shared<PersonView>(view));
    }

    void start() {
        int choice;
        do {
            view.displayMenu();
            choice = std::stoi(view.getInput("Enter action: "));

            switch (choice) {
            case 1: addStudent(); break;
            case 2: addTeacher(); break;
            case 3: printAll(); break;
            case 4: store(); break;
            case 5: break;
            default: view.publish("Unknown action.");
            }
        } while (choice != 5);
    }

private:
    PersonView& view;
    ObservablePersonRepository& repository;

    void addStudent() {
        std::string name = view.getInput("Enter name: ");
        std::string phone = view.getInput("Enter phone: ");
        repository.add(PersonFactory::createPerson(PersonFactory::PersonType::Student, name, phone));
    }

    void addTeacher() {
        std::string name = view.getInput("Enter name: ");
        std::string phone = view.getInput("Enter phone: ");
        repository.add(PersonFactory::createPerson(PersonFactory::PersonType::Teacher, name, phone));
    }

    void printAll() {
        std::vector<std::string> toStringPersons = repository.findAllCached();

        for (const auto& toStringPerson : toStringPersons) {
            std::cout << toStringPerson << std::endl;
        }
    }

    void store() {
        std::string collection = view.getInput("Enter collection: ");
        repository.persist(collection);
    }
};

int main() {
    PersonView view;
    FilePersonRepository fileRepository;
    PersonController controller(view, fileRepository);
    controller.start();
    return 0;
}