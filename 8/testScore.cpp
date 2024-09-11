#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // For std::sort
#include <limits>     // For std::numeric_limits
#include <stdexcept>  // For std::domain_error

// Student_info 구조체 정의
struct Student_info {
    std::string name;
    double midterm;
    double finalterm;
    std::vector<double> homeworks;

    // 학생 정보를 설정하는 함수
    bool read(std::istream& in) {
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
    double final_grade() const {
        if (homeworks.empty()) {
            throw std::domain_error("빈 벡터에서 중앙값을 계산할 수 없습니다.");
        }
        double medianValue = median(homeworks);
        return grade(midterm, finalterm, medianValue);
    }

    // 학생 정보를 출력하는 함수
    void print_info() const {
        try {
            double finalScore = final_grade();
            std::cout << name << " " << finalScore << std::endl;
        } catch (const std::domain_error& e) {
            std::cerr << "에러: " << e.what() << std::endl;
        }
    }

private:
    // 과제 점수 입력 함수
    static std::istream& read_hw(std::istream& in, std::vector<double>& homeworks) {
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
    static double median(const std::vector<double>& vec) {
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

    // 점수 계산 함수
    static double grade(double midterm, double finalterm, double homework) {
        return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
    }
};

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
