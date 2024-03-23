#include <fstream>
#include <iostream>
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
        int arr[2] = {-1, -1};
        for (char ch : line) {
            int num = charToInt(ch);
            if (num != -1) {
                if (arr[0] == -1) {
                    arr[0] = num;
                } else {
                    arr[1] = num;
                }
            }
        }
        if (arr[1] == -1) arr[1] = arr[0];
        sum += arr[0] * 10 + arr[1];
    }
    std::cout << "The sum is " << sum << " (answer of first star)" << std::endl;

    inputFile.clear();   // Clear the end-of-file state
    inputFile.seekg(0);  // Move the file cursor to the beginning of the file

    sum = 0;
    while (std::getline(inputFile, line)) {
        int arr[2] = {-1, -1};
        for (char ch : line) {
            int num = charToInt(ch);
            if (num != -1) {
                if (arr[0] == -1) {
                    arr[0] = num;
                } else {
                    arr[1] = num;
                }
            } else {
                num = checkInMap(numsMap, line);
                if (num != -1) {
                    if (arr[0] == -1) {
                        arr[0] = num;
                    } else {
                        arr[1] = num;
                    }
                }
            }
        }
        if (arr[1] == -1) arr[1] = arr[0];
        sum += arr[0] * 10 + arr[1];
    }
    std::cout << "The sum is " << sum << " (answer of second star)" << std::endl;
    inputFile.close();
    return 0;
}
