#include <iostream>
#include <vector>
#include "student_info.h"

// 불합격 학생들을 추출하는 함수
std::vector<Student_info> extract_fails(const std::vector<Student_info>& students, double fail_threshold) {
    std::vector<Student_info> fails;
    for (auto it = students.cbegin(); it != students.cend(); ++it) {
        if (it->get_final_score() <= fail_threshold) {
            fails.push_back(*it);
        }
    }
    return fails;
}

int main() {
    std::vector<Student_info> students;
    Student_info student;

    std::cout << "학생 정보를 입력하세요 (입력을 끝내려면 Ctrl+D를 누르세요):" << std::endl;
    while (student.read(std::cin)) {
        students.push_back(student);
    }

    std::cout << "\n학생 점수:\n";
    for (auto it = students.cbegin(); it != students.cend(); ++it) {
        it->print_info();
    }

    double fail_threshold = 60.0; // 불합격 기준 점수 설정 (예: 60점)
    std::vector<Student_info> failed_students = extract_fails(students, fail_threshold);

    std::cout << "\n불합격 학생들:\n";
    for (auto it = failed_students.cbegin(); it != failed_students.cend(); ++it) {
        it->print_info();
    }

    return 0;
}
