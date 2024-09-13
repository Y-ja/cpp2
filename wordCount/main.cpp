#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream in("lyrics.txt");

    if (!in) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (in >> word) {
        ++word_count[word];
    }

    in.close();

    std::cout << "Word frequencies:" << std::endl;
    for (const auto& pair : word_count) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
