#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <string>
#include <algorithm>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void publish(const std::string& message) = 0;
};

class Observable {
public:
    void subscribe(std::shared_ptr<IObserver> observer) {
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

class PersonRepository : public Observable {
public:
    static PersonRepository& getInstance() {
        static PersonRepository instance;
        return instance;
    }

    void add(std::shared_ptr<Person> person) {
        persons.push_back(person);
        publishAll("Person added: " + person->getName());
    }

    std::vector<std::string> findAll() const {
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
                out << person->serialize();
            }
            out.close();
        }
    }

private:
    PersonRepository() = default;
    std::vector<std::shared_ptr<Person>> persons;
};

class PersonView : public IObserver {
public:
    PersonView() {
        PersonRepository::getInstance().subscribe(std::make_shared<PersonView>(*this));
    }

    void publish(const std::string& message) override {
        std::cout << "[Notification] " << message << std::endl;
    }

    void displayMenu() const {
        std::cout << "1. Add Student\n2. Add Teacher\n3. Display All\n4. Save to File\n5. Exit\n";
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
    PersonController(PersonView& view) : view(view) {}

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
    void addStudent() {
        std::string name = view.getInput("Enter name: ");
        std::string phone = view.getInput("Enter phone: ");
        PersonRepository::getInstance().add(PersonFactory::createPerson(PersonFactory::PersonType::Student, name, phone));
    }

    void addTeacher() {
        std::string name = view.getInput("Enter name: ");
        std::string phone = view.getInput("Enter phone: ");
        PersonRepository::getInstance().add(PersonFactory::createPerson(PersonFactory::PersonType::Teacher, name, phone));
    }

    void printAll() {
        std::vector<std::string> toStringPersons = PersonRepository::getInstance().findAll();

        for (const auto& toStringPerson : toStringPersons) {
            std::cout << toStringPerson << std::endl;
        }
    }

    void store() {
        std::string filename = view.getInput("Enter filename: ");
        PersonRepository::getInstance().persist(filename);
    }

    PersonView& view;
};

int main() {
    PersonView view;
    PersonController controller(view);
    controller.start();
    return 0;
}