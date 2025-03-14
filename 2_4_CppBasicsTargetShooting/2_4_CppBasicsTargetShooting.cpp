#include <iostream>
#include <cmath>


static std::string getCategory(int shotCount) {
    if (shotCount <= 5) {
        return "Sniper";
    }
    else if (shotCount <= 10) {
        return "Shooter";
    }
    else {
        return "Newbie";
    }
}

static int calculateScore(double x, double y) {
    double distance = sqrt(x * x + y * y);

    if (distance <= 1.0) {
        return 10;
    }
    else if (distance <= 2.0) {
        return 5;
    }
    else {
        return 0;
    }
}

int main() {
    int limitScore = 50; 
    int totalScore = 0;   
    int shotsCount = 0;   

    std::cout << "Target shooting game starts..." << std::endl;

    while (totalScore < limitScore) {
        double x, y;
        std::cout << "Enter shot coordinates (x y): ";
        std::cin >> x >> y;

        int score = calculateScore(x, y);
        totalScore += score;
        shotsCount++;

        std::cout << "Result score is " << score << std::endl
                  << "Total score is " << totalScore << std::endl;
    }

    std::string category = getCategory(shotsCount);
    std::cout << "Your category is: " << category << std::endl;

    return 0;
}