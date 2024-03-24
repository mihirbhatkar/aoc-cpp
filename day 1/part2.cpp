#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else
        return -1;
}

int checkInMap(std::map<std::string, int>& map, std::string& str) {
    std::string numsArray[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 9; i > 0; --i) {
        if (str.find(numsArray[i - 1]) == 0) {
            str.erase(0, numsArray[i - 1].length());
            return i;
        }
    }
    return -1;
}

int main() {
    std::string numsArray[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::map<std::string, int> numsMap;

    for (int i = 0; i < 9; ++i) {
        numsMap[numsArray[i]] = i + 1;
    }

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    int sum = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::map<int, int> temp;

        // check for substrings
        for (std::string st : numsArray) {
            int pos = line.find(st);
            while ((pos = line.find(st, pos)) != std::string::npos) {
                temp[pos] = numsMap[st];
                pos += st.length();
            }
        }

        // check for numbers
        for (int i = 0; i < line.size(); i++) {
            int n = charToInt(line[i]);
            if (n != -1) temp[i] = n;
        }

        int lowestKey = std::numeric_limits<int>::max();
        for (const auto& pair : temp) {
            if (pair.first < lowestKey) {
                lowestKey = pair.first;
            }
        }

        int highestKey = std::numeric_limits<int>::min();
        for (const auto& pair : temp) {
            if (pair.first > highestKey) {
                highestKey = pair.first;
            }
        }

        if (line == "four2tszbgmxpbvninebxns6nineqbqzgjpmpqr") {
            for (const auto& pair : temp) {
                std::cout << "key " << pair.first << " value " << pair.second << std::endl;
            }
        }
        sum += temp[lowestKey] * 10 + temp[highestKey];
        std::cout << temp[lowestKey] << temp[highestKey] << " for " << line << std::endl;
    }
    std::cout
        << "The sum is " << sum << " (answer of second star)" << std::endl;
    inputFile.close();
    return 0;
}
