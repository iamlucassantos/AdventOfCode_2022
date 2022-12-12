//
// Created by Lucas dos Santos on 12/12/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>

int get_score(int opponent, int player) {

    int diff = player - opponent;

    int score = player;

    if (diff == 0) {
        score += 3;
    } else if (diff == 1 | diff == -2) {
        score += 6;
    } else {
        score += 0;
    }

    return score;
}

void day2(const int part) {

    std::map<char, int> p1 = {
            {'A', 1},
            {'B', 2},
            {'C', 3}
    };

    std::map<char, int> p2 = {
            {'X', 1},
            {'Y', 2},
            {'Z', 3},
    };

    if (part == 1) {
        // PART 1
        std::cout << "Day 2: Part 1" << std::endl;

        std::ifstream file;
        file.open("../input/day2.txt");

        std::string line;

        int total = 0;
        if (file.is_open()) {
            while (getline(file, line)) {

                int opponent = p1[line[0]];
                int player = p2[line[2]];

                int score = get_score(opponent, player);

                total += score;

            }
            file.close();

            std::cout << "Total: " << total << std::endl;
        }

    } else if (part == 2) {
        // PART 2
        std::cout << "Day 2: Part 2" << std::endl;

        std::ifstream file;
        file.open("../input/day2.txt");

        std::string line;
        int total = 0;
        if (file.is_open()) {
            while (getline(file, line)) {

                int opponent = p1[line[0]];
                int player = p2[line[2]];

                if (player == 1) {
                    player = opponent - 1;

                    if (player == 0) {
                        player = 3;
                    }

                } else if (player == 2) {
                    player = opponent;

                } else if (player == 3) {
                    player = opponent + 1;

                    if (player == 4) {
                        player = 1;
                    }

                }

                int score = get_score(opponent, player);

                total += score;
            }
        }

        file.close();

        std::cout << "Total: " << total << std::endl;

    }
}