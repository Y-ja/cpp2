// median.cpp
#include "median.h"
#include <algorithm>  // For std::sort
#include <stdexcept>  // For std::domain_error

// 중앙값 계산 함수 정의
double median(const std::vector<double>& vec) {
    if (vec.empty()) {
        throw std::domain_error("빈 벡터에서 중앙값을 계산할 수 없습니다.");
    }
    std::vector<double> vec2 = vec;
    std::sort(vec2.begin(), vec2.end());
    size_t size = vec2.size();
    if (size % 2 == 0) {
        return (vec2[size / 2 - 1] + vec2[size / 2]) / 2.0;
    } else {
        return vec2[size / 2];
    }
}
