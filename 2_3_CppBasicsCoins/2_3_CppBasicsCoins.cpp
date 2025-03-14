#include <iostream>
#include <vector>

const std::vector<int> coin_types = { 1000, 500, 200, 100, 50, 10, 5, 1 };

int main() {
    int amount;
    std::cout << "Enter sum in cents: ";
    std::cin >> amount;

    std::vector<int> result;
    for (int coin : coin_types) {
        while (amount >= coin) {
            result.push_back(coin);
            amount -= coin;
        }
    }

    std::cout << "Coins: ";
    for (int coin : result) {
        std::cout << coin << " ";
    }
    std::cout << std::endl;

    return 0;
}