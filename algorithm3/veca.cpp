#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num[] = {1, 2, 3, 4, 5};          // 배열 선언
    std::vector<int> vec(num, num + 5);   // 벡터를 배열로 초기화

    // 배열과 벡터의 요소가 동일한지 확인
    if (std::equal(std::begin(num), std::end(num), vec.begin())) {
        std::cout << "num and vec have the same elements" << std::endl;
    } else {
        std::cout << "num and vec don't have the same elements" << std::endl;
    }

    // 벡터의 요소를 역순으로 출력
    std::cout << "Vector elements in reverse order:" << std::endl;
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
