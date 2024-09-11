#include <iostream>
#include <sstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wordCount;
    std::string line;
    
    std::cout << "텍스트를 입력하세요 (새 줄에 'END'를 입력하여 종료):" << std::endl;

    // 표준 입력에서 줄을 읽어옵니다.
    while (std::getline(std::cin, line) && line != "END") {
        std::istringstream iss(line);
        std::string word;

        // 줄에서 각 단어를 처리합니다.
        for (; iss >> word;) {
            ++wordCount[word];
        }
    }

    // 단어 개수를 출력합니다.
    std::cout << "\n단어 개수:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
