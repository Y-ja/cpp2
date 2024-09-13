#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> v1(num, num + 10);  // 배열을 벡터로 초기화

    int num2[] = {50, 60};
    std::vector<int> v2(num2, num2 + 2);  // 배열을 벡터로 초기화

    // 벡터 내용을 출력하여 확인
    std::cout << "v1: ";
    for (int n : v1) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    std::cout << "v2: ";
    for (int n : v2) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    // v1에서 v2를 검색
    auto it = std::search(v1.begin(), v1.end(), v2.begin(), v2.end());

    // while문을 사용하여 검색 결과 확인
    while (true) {
        if (it != v1.end()) {
            std::cout << "Subvector v2 found in v1 starting at index " << std::distance(v1.begin(), it) << std::endl;
            break;
        } else {
            std::cout << "Subvector v2 not found in v1" << std::endl;
            break;
        }
    }

    return 0;
}
