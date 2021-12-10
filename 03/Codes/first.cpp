#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>

int main() {

    // Get datas
    std::ifstream inputs{"../inputs.txt"};
    std::vector<std::vector<bool>> datas;

    {

        std::string buffer;
        std::size_t artificialIndex{0};
        while (std::getline(inputs, buffer)) {

            datas.push_back(std::vector<bool>{});
            for (char c : buffer) datas[artificialIndex].push_back(static_cast<bool>(c-'0'));
            artificialIndex++;

        }

    }

    //Initialise loop
    std::bitset<sizeof(unsigned long long)*8> gamma, epsilon;

    // loop and print results
    for (std::size_t x{0}; x < datas[0].size(); x++) {

        std::size_t countBits{0};
        for (std::size_t y{0}; y < datas.size() && countBits < datas.size()/2+1; y++) {

            countBits += datas[y][x];

        }

        gamma[datas[0].size()-1-x] = (countBits > datas.size()/2);
        epsilon[datas[0].size()-1-x] = !gamma[datas[0].size()-1-x];

    }

    // Solution
    std::cout << "gamma = " << gamma.to_ullong() << "\nepsilon = " << epsilon.to_ullong() << "\nenergy consomation = " << gamma.to_ullong()*epsilon.to_ullong();

    return 0;

}