#include "student_info.h"
#include "grade.h"
#include <limits> // For std::numeric_limits

// 학생 정보를 설정하는 함수
bool Student_info::read(std::istream& in) {
    // 기존 입력 처리를 하기 전에 변수 초기화
    name.clear();
    midterm = finalterm = 0;
    final_score = 0;  // 초기화

    double homework;  // 과제 점수를 위한 임시 변수

    if (in >> name >> midterm >> finalterm >> homework) {
        // 최종 점수 계산
        final_score = calculate_final_score(midterm, finalterm, homework);
        return true;  // 성공적으로 읽었음을 반환
    } else {
        return false; // 입력 실패 시
    }
}

// 학생 정보를 출력하는 함수
void Student_info::print_info() const {
    std::cout << name << " " << final_score << std::endl;
}

// 최종 점수 계산 함수
double Student_info::calculate_final_score(double midterm, double finalterm, double homework) {
    return grade(midterm, finalterm, homework);
}
