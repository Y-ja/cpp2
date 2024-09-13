#include "grade.h"

// 점수 계산 함수 정의
double grade(double midterm, double finalterm, double homework) {
    // 점수 계산 방식
    const double midterm_weight = 0.3;
    const double finalterm_weight = 0.5;
    const double homework_weight = 0.2;

    return (midterm * midterm_weight) + (finalterm * finalterm_weight) + (homework * homework_weight);
}
