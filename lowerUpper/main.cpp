#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // std::isupper 사용을 위한 헤더 파일

// 문자열이 모두 대문자인지 확인하는 함수
bool isUpper(const std::string& s) {
    for (char c : s) {
        if (!std::isupper(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> lower, upper;
    std::string s;

    // 문자열 입력받기
    std::cout << "Enter words (Ctrl+D to end input):" << std::endl;
    while (std::cin >> s) {
        if (isUpper(s)) {
            upper.push_back(s);
        } else {
            lower.push_back(s);
        }
    }

    // "lower" 벡터 출력
    std::cout << "\nLowercase words:" << std::endl;
    for (const auto& word : lower) {
        std::cout << word << std::endl;
    }

    // "upper" 벡터 출력
    std::cout << "\nUppercase words:" << std::endl;
    for (const auto& word : upper) {
        std::cout << word << std::endl;
    }

    return 0;
}
