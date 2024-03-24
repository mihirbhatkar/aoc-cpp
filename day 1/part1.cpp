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
int main() {
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
    inputFile.close();
    return 0;
}
