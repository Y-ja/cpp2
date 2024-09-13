#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 값 3을 제거하기 위한 작업
    auto new_end = std::remove(vec.begin(), vec.end(), 3);

    // 벡터의 끝을 새로운 끝으로 조정
    vec.erase(new_end, vec.end());

    // 변경된 벡터의 내용을 출력
    std::cout << "Modified vector: ";
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
