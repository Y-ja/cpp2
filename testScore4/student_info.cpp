#include "student_info.h"
#include "grade.h"    // For the grade function
#include <algorithm>  // For std::sort
#include <limits>     // For std::numeric_limits
#include <stdexcept>  // For std::domain_error

// 학생 정보를 설정하는 함수
bool Student_info::read(std::istream& in) {
    // 기존 입력 처리를 하기 전에 변수 초기화
    name.clear();
    midterm = finalterm = 0;
    homeworks.clear();

    if (in >> name >> midterm >> finalterm) {
        read_hw(in, homeworks);
        return true;  // 성공적으로 읽었음을 반환
    } else {
        return false; // 입력 실패 시
    }
}

// 최종 점수 계산 함수
double Student_info::get_final_score() const {
    if (homeworks.empty()) {
        throw std::domain_error("빈 리스트에서 중앙값을 계산할 수 없습니다.");
    }
    double medianValue = median(homeworks);
    return grade(midterm, finalterm, medianValue);
}

// 학생 정보를 출력하는 함수
void Student_info::print_info() const {
    try {
        double finalScore = get_final_score();
        std::cout << name << " " << finalScore << std::endl;
    } catch (const std::domain_error& e) {
        std::cerr << "에러: " << e.what() << std::endl;
    }
}

// 과제 점수 입력 함수
std::istream& Student_info::read_hw(std::istream& in, std::list<double>& homeworks) {
    homeworks.clear();
    double homework;
    while (in >> homework) {
        homeworks.push_back(homework);
    }
    if (in.eof()) {
        in.clear(); // Clear the EOF flag
    }
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input
    return in;
}

// 중앙값 계산 함수
double Student_info::median(const std::list<double>& lst) {
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
