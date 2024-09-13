#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <list>
#include <string>

// Student_info 구조체 정의
struct Student_info {
    std::string name;
    double midterm;
    double finalterm;
    std::list<double> homeworks;

    // 학생 정보를 설정하는 함수
    bool read(std::istream& in);

    // 최종 점수 계산 함수
    double get_final_score() const;

    // 학생 정보를 출력하는 함수
    void print_info() const;

private:
    // 과제 점수 입력 함수
    static std::istream& read_hw(std::istream& in, std::list<double>& homeworks);

    // 중앙값 계산 함수
    static double median(const std::list<double>& lst);
};

#endif // STUDENT_INFO_H
