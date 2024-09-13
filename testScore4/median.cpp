#include "median.h"
#include <algorithm>  // For std::sort
#include <stdexcept>  // For std::domain_error

// 중앙값 계산 함수 정의
double median(const std::list<double>& lst) {
    if (lst.empty()) {
        throw std::domain_error("빈 리스트에서 중앙값을 계산할 수 없습니다.");
    }

    std::list<double> sorted_lst = lst;
    sorted_lst.sort(); // std::list의 sort 메서드를 사용

    auto size = std::distance(sorted_lst.begin(), sorted_lst.end());
    auto mid = size / 2;
    
    auto it = sorted_lst.begin();
    std::advance(it, mid);

    if (size % 2 == 0) {
        auto it_prev = it;
        std::advance(it_prev, -1);
        return (*it + *it_prev) / 2.0;
    } else {
        return *it;
    }
}
