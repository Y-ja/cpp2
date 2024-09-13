#include <iostream>
#include <vector>
#include <algorithm>

// 50보다 큰 값을 찾는 함수
bool grater50(int num) {
    return num > 50;
}

int main() {
    int num[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::vector<int> vec(num, num + 10);

    // 90을 찾기
    auto it = std::find(vec.begin(), vec.end(), 90);

    if (it != vec.end()) {
        std::cout << "Found value: " << *it << std::endl;
    } else {
        std::cout << "Value not found" << std::endl;
    }

    // 50보다 큰 첫 번째 값을 찾기
    auto it2 = std::find_if(vec.cbegin(), vec.cend(), grater50);

    if (it2 != vec.cend()) {
        std::cout << "First value greater than 50: " << *it2 << std::endl;
    } else {
        std::cout << "No value greater than 50 found" << std::endl;
    }

    // 50보다 큰 모든 값을 찾고 출력하기
    auto it3 = vec.cbegin();
    while (it3 != vec.cend()) {
        // 조건에 맞는 값을 찾기
        it3 = std::find_if(it3, vec.cend(), grater50);
        if (it3 != vec.cend()) {
            std::cout << "Value greater than 50: " << *it3 << std::endl;
            // 다음 검색을 위해 it3을 다음 위치로 이동
            ++it3;
        }
    }

    return 0;
}
