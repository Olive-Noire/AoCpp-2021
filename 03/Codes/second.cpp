#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>

int main() {

    // Get datas
    std::ifstream inputs{"../inputs.txt"};
    std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>> datas;

    {

        std::string buffer;
        for (std::size_t index{0}; std::getline(inputs, buffer); index++) {

            datas.first.push_back(std::vector<bool>{});
            datas.second.push_back(std::vector<bool>{});

            for (char c : buffer) {
                
                datas.first[index].push_back(static_cast<bool>(c-'0'));
                datas.second[index].push_back(datas.first[index].back());

            }

        }

    }

    // loop and print results
    for (std::size_t x{0}; x < datas.first[0].size(); x++) {

        std::pair<std::size_t, std::size_t> count{0, 0};

        for (std::size_t y{0}; y < datas.first.size() && count.first < datas.first.size()/2+1; y++) count.first += datas.first[y][x];
        for (std::size_t y{0}; y < datas.second.size() && count.second < datas.second.size()/2+1; y++) count.second += datas.second[y][x];

        const std::pair<bool, bool> conditions{count.first >= (datas.first.size()-count.first), count.second < (datas.second.size()-count.second)};

        std::cout << "\nsize o = " << datas.first.size() << "\ncount o = " << count.first << "\no : " << conditions.first << "\nsize c = " << datas.second.size() << "\ncount c = " << count.second << "\nc : " << conditions.second;

        for (std::size_t i{0}; i < datas.first.size() && datas.first.size() > 1; i++) {

            if (datas.first[i][x] != conditions.first) {
                    
                datas.first.erase(datas.first.begin()+i);
                i--;

            }

        }

        for (std::size_t i{0}; i < datas.second.size() && datas.second.size() > 1; i++) {

            if (datas.second[i][x] != conditions.second) {
                    
                datas.second.erase(datas.second.begin()+i);
                i--;

            }

        }

        for (std::size_t i{count.first}; i < datas.first.size() && datas.first.size() > 1; i++) datas.first.erase(datas.first.begin()+i);
        for (std::size_t i{count.second}; i < datas.second.size() && datas.second.size() > 1; i++) datas.second.erase(datas.second.begin()+i);

        std::cout << "\n\nlefts o :\n";
        for (auto d : datas.first) {

            for (auto b : d) std::cout << b;
            std::cout << std::endl;

        }

        std::cout << "\nlefts c :\n";
        for (auto d : datas.second) {

            for (auto b : d) std::cout << b;
            std::cout << std::endl;

        }

    }

    std::pair<std::bitset<sizeof(unsigned long long)*8>, std::bitset<sizeof(unsigned long long)*8>> rating;

    for (std::size_t i{0}; i < datas.first[0].size() && i < rating.first.size(); i++) rating.first[i] = datas.first[0][datas.first[0].size()-1-i];
    for (std::size_t i{0}; i < datas.second[0].size() && i < rating.second.size(); i++) rating.second[i] = datas.second[0][datas.second[0].size()-1-i];

    // Solution
    std::cout << "\noxygen generator rating = " << rating.first.to_ullong() << "\nCO2 scrubber rating = " << rating.second.to_ullong() << "\nlife support rating = " << rating.first.to_ullong()*rating.second.to_ullong();

    return 0;

}