#include <iostream>
#include <string>

int main() {
    std::cout << "이름을 입력하세요 -> ";
    std::string name;
    std::cin >> name;

    std::cout << "중간고사와 기말고사 점수를 입력하세요 -> ";
    double midterm, finalterm;
    std::cin >> midterm >> finalterm;

    double sum = 0.0;
    int count = 0;

    std::cout << "과제 점수를 입력하세요 (숫자가 아닌 값을 입력하여 종료) -> ";
    double homework;
    while (std::cin >> homework) {
        sum += homework;
        count++;
    }

    // 과제 점수의 평균을 계산합니다
    double averageHomework = (count > 0) ? (sum / count) : 0;
    // 최종 점수를 계산합니다
    double finalScore = 0.4 * midterm + 0.4 * finalterm + 0.2 * averageHomework;
    std::cout << "최종 점수: " << finalScore << std::endl;

    return 0;
}
