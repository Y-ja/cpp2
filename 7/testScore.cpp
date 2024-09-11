#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // For std::sort
#include <limits>     // For std::numeric_limits
#include <stdexcept>  // For std::domain_error

// read_hw 함수 정의
std::istream& read_hw(std::istream& in, std::vector<double>& homeworks)
{
    homeworks.clear();
    double homework;
    
    // 입력 스트림 상태가 정상인 경우에만 계속 읽음
    if (in) {
        while (in >> homework) {
            homeworks.push_back(homework);
        }
        
        // 입력 오류가 발생한 경우 스트림 상태를 정리
        if (in.fail()) {
            in.clear(); // Clear the error state
        }
    }

    return in;
}

// median 함수 정의
double median(const std::vector<double>& vec)
{
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

// grade 함수 정의
double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

// garade 함수 정의
double garade(double midterm, double finalterm, const std::vector<double>& homework)
{
    if (homework.empty()) {
        throw std::domain_error("빈 벡터에서 중앙값을 계산할 수 없습니다.");
    }
    
    double medianValue = median(homework);
    return grade(midterm, finalterm, medianValue);
}

int main() {
    std::cout << "이름을 입력하세요 -> ";
    std::string name;
    std::cin >> name;

    std::cout << "중간고사와 기말고사 점수를 입력하세요 -> ";
    double midterm, finalterm;
    std::cin >> midterm >> finalterm;

    std::vector<double> home;
    std::cout << "과제 점수를 입력하세요 (숫자가 아닌 값을 입력하여 종료) -> ";
    
    // 과제 점수 입력 함수 호출
    read_hw(std::cin, home);

    // 중앙값을 계산하고 최종 점수를 계산합니다
    try {
        double finalScore = garade(midterm, finalterm, home);
        std::cout << "최종 점수: " << finalScore << std::endl;
    } catch (const std::domain_error& e) {
        std::cerr << "에러: " << e.what() << std::endl;
    }

    return 0;
}
