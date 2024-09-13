#include <iostream>
#include <list>
#include <fstream>
#include "student_info.h"

// 불합격 학생들을 추출하는 함수
std::list<Student_info> extract_fails(const std::list<Student_info>& students, double fail_threshold) {
    std::list<Student_info> fails;
    for (const auto& student : students) {
        if (student.get_final_score() <= fail_threshold) {
            fails.push_back(student);
        }
    }
    return fails;
}

int main() {
    std::list<Student_info> students;
    Student_info student;

    // 파일 입력을 위해 std::ifstream 사용
    std::ifstream infile("student_scores.txt");
    if (!infile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1; // 오류 발생 시 종료
    }

    std::cout << "학생 정보를 읽고 있습니다..." << std::endl;
    while (student.read(infile)) {
        students.push_back(student);
    }

    infile.close();

    std::cout << "\n학생 점수:\n";
    for (const auto& s : students) {
        s.print_info();
    }

    double fail_threshold = 60.0; // 불합격 기준 점수 설정 (예: 60점)
    std::list<Student_info> failed_students = extract_fails(students, fail_threshold);

    std::cout << "\n불합격 학생들:\n";
    for (const auto& s : failed_students) {
        s.print_info();
    }

    return 0;
}
