#include <iostream>
#include <vector>
#include <algorithm>

int square(int num) {
    return num * num;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result;

    // std::transform을 사용하여 vec의 각 요소에 대해 square 함수를 적용
    // std::back_inserter를 사용하여 결과를 result 벡터에 추가
    std::transform(vec.cbegin(), vec.cend(), std::back_inserter(result), square);

    // 결과 출력
    std::cout << "Result: ";
    for (int num : result) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
