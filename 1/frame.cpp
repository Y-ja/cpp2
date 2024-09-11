#include <iostream>
#include <string>

int main() {
    std::cout << "이름을 입력하세요 -> ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "안녕하세요, " + name + "!";

    // 첫 번째 줄과 두 번째 줄을 만들기 위해 필요한 변수들
    const std::string firstLine(greeting.size() + 4, '*');
    const std::string secondLine = "* " + std::string(greeting.size(), ' ') + " *";

    // 출력
    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;

    return 0;
}
