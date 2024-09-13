#include <iostream>
#include <vector>
#include <numeric>  // std::accumulate를 사용하기 위한 헤더

int main() {
    std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    // std::accumulate를 사용하여 벡터의 모든 요소를 합산
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);

    // 결과 출력
    std::cout << "sum -> " << sum << std::endl;

    return 0;
}
