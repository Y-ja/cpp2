#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>

class Student_info {
public:
    // 학생 정보 읽기
    bool read(std::istream& in);
    // 학생 정보 출력
    void print_info() const;

private:
    std::string name;
    double midterm;
    double finalterm;
    double final_score;

    // 최종 점수 계산
    double calculate_final_score(double midterm, double finalterm, double homework);
};

#endif // STUDENT_INFO_H
