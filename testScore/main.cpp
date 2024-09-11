// main.cpp
#include <iostream>
#include <vector>
#include "student_info.h"

int main() {
    std::vector<Student_info> students;
    Student_info student;

    std::cout << "학생 정보를 입력하세요 (입력을 끝내려면 Ctrl+D를 누르세요):" << std::endl;
    while (true) {
        if (!student.read(std::cin)) {
            break; // 입력이 실패하면 루프 종료
        }
        students.push_back(student);
    }

    std::cout << "\n학생 점수:\n";
    for (const auto& s : students) {
        s.print_info();
    }

    return 0;
}
