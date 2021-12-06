#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
    unsigned int &buffer{deepDatas[0]}, count{0};
    std::cout << buffer << " (N/A - no previous measurement)";

    // loop and print results
    for (std::size_t i{1}; i < deepDatas.size(); i++) {

        std::cout << std::endl << deepDatas[i];
        if (deepDatas[i] > buffer) {
            
            count++;
            std::cout << " (increased)";

        } else {

            std::cout << " (decreased)";

        }

        buffer = deepDatas[i];

    }

    // Solution
    std::cout << "\nnumber of \"increased\" : " << count;

    return 0;

}