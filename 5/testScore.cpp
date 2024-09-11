#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // For std::sort
#include <limits>     // For std::numeric_limits

int main() {
    std::cout << "이름을 입력하세요 -> ";
    std::string name;
    std::cin >> name;

    std::cout << "중간고사와 기말고사 점수를 입력하세요 -> ";
    double midterm, finalterm;
    std::cin >> midterm >> finalterm;

    std::vector<double> home;  // 벡터 이름을 home으로 변경
    std::cout << "과제 점수를 입력하세요 (숫자가 아닌 값을 입력하여 종료) -> ";
    double homework;

    // 과제 점수를 벡터에 저장합니다
    while (std::cin >> homework) {
        home.push_back(homework);
    }

    // cin에서 비숫자 입력을 처리하여 종료합니다
    std::cin.clear();  // Clear the error state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the remaining input

    // 중앙값을 계산합니다
    double median = 0.0;
    if (!home.empty()) {  // 벡터가 비어 있지 않은 경우
        std::sort(home.begin(), home.end());  // 벡터를 정렬합니다
        size_t size = home.size();
        
        if (size % 2 == 0) {
            // 짝수 개수의 요소가 있을 때 중앙값은 가운데 두 값의 평균입니다
            median = (home[size / 2 - 1] + home[size / 2]) / 2.0;
        } else {
            // 홀수 개수의 요소가 있을 때 중앙값은 가운데 값입니다
            median = home[size / 2];
        }
    }

    // 최종 점수를 계산합니다
    double finalScore = 0.4 * midterm + 0.4 * finalterm + 0.2 * median;
    std::cout << "최종 점수: " << finalScore << std::endl;

    return 0;
}
