#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

using SlidingWindow = std::array<unsigned int, 3>;

unsigned int Sum(const SlidingWindow &w) { return w[0]+w[1]+w[2]; }

int main() {

    // Get datas
    std::ifstream inputs{"../inputs.txt"};
    std::vector<unsigned int> deepDatas;

    {

        std::string buffer;
        while (std::getline(inputs, buffer)) {

            deepDatas.push_back(0);
            std::istringstream{buffer} >> deepDatas[deepDatas.size()-1];

        }

    }

    // Initialize loop
    SlidingWindow slider{deepDatas[0], deepDatas[1], deepDatas[2]};
    std::size_t count{0};

    std::cout << Sum(slider) << " (N/A - no previous measurement)";

    // loop and print results
    for (std::size_t i{3}; i < deepDatas.size(); i++) {

        SlidingWindow buffer{slider[1], slider[2], deepDatas[i]};

        std::cout << std::endl << Sum(buffer);
        if (Sum(buffer) > Sum(slider)) {
            
            count++;
            std::cout << " (increased)";

        } else if (Sum(buffer) == Sum(slider)) {

            std::cout << " (no change)";

        } else {

            std::cout << " (decreased)";

        }

        slider = buffer;

    }

    // Solution
    std::cout << "\nnumber of \"increased\" : " << count;

    return 0;

}