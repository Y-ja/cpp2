#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    int num2[5];

    std::copy(num, num + 5, num2);

    std::cout << "num2: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << num2[i] << ' ';
    }
    std::cout << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(num[i]);
    }

    // std::copy의 대상 범위는 vec의 begin()부터 시작
    std::copy(num, num + 5, vec.begin());

    std::cout << "vec: ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
