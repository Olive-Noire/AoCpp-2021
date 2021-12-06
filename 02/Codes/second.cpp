#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>

enum class Move {FORWARD = 0, DOWN, UP};
using Command = std::pair<Move, unsigned int>;

int main() {

    // Get datas
    std::ifstream inputs{"../inputs.txt"};
    std::vector<Command> datas;

    {

        std::string buffer;
        while (std::getline(inputs, buffer)) {

            std::string indication{buffer};

            indication.erase(std::find(indication.begin(), indication.end(), ' '), indication.end());
            buffer.erase(buffer.begin(), std::find(buffer.begin(), buffer.end(), ' ')+1);

            Command c;

            if (indication == "forward") {

                c.first = Move::FORWARD;

            } else if (indication == "down") {

                c.first = Move::DOWN;

            } else if (indication == "up") {

                c.first = Move::UP;

            }

            std::istringstream{buffer} >> c.second;
            datas.push_back(c);

        }

    }

    // Initialize loop
    std::pair<unsigned int, int> position{0, 0};
    int aim{0};

    for (std::size_t i{0}; i < datas.size(); i++) {

        switch (datas[i].first) {

            case Move::FORWARD:
                position.first += datas[i].second;
                position.second += datas[i].second*aim;
            break;

            case Move::DOWN:
                aim += datas[i].second;
            break;

            case Move::UP:
                aim -= datas[i].second;
            break;

        }

    }

    // Solution
    std::cout << "horizontal = " << position.first << "\ndepth = " << position.second << "\nposition = " << position.first*position.second;

    return 0;

}