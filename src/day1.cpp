//
// Created by Lucas dos Santos on 12/12/2022.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void compare(std::vector<int> &vector, int total) {
    // compares if the total sum is higher than one of the top three numbers
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] < total) {
            auto replaced = vector[i];
            vector[i] = total;
            compare(vector, replaced);
            break;
        }
    }
}


void day1(const int part) {

    if (part == 1) {
        // PART 1
        std::cout << "Day 1: Part 1" << std::endl;
        std::ifstream file;
        file.open("../input/day1.txt");

        std::string line;

        int total = 0;
        int max = 0;

        if (file.is_open()) {
            while (getline(file, line)) {

                if (line.size() == 0) {
                    max = std::max(total, max);
                    total = 0;
                } else {
                    total += std::stoi(line);
                }

            }
            file.close();
            max = std::max(total, max);
        }

        std::cout << "Max: " << max << std::endl;
    } else if (part == 2) {
        // PART 2
        std::cout << "Day 1: Part 2" << std::endl;

        std::ifstream file;
        file.open("../input/day1.txt");

        std::string line;

        int total = 0;
        std::vector<int> numbers{0, 0, 0};

        while (getline(file, line)) {
            if (line.size() == 0) {
                compare(numbers, total);
                total = 0;
            } else {
                total += std::stoi(line);
            }
        }

        compare(numbers, total);

        int sum;
        for (auto &number: numbers) {
            sum += number;
            std::cout << number << ", ";
        }
        std::cout << "Sum: " << sum << std::endl;

    }


};