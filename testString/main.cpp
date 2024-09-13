#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 주어진 문자열 벡터를 프레임으로 둘러싸는 함수
vector<string> frame(const vector<string>& lines) {
    vector<string> framed;
    
    // 빈 벡터를 처리하기 위해 예외 처리
    if (lines.empty()) {
        return framed;
    }

    // 가장 긴 문자열의 길이를 찾기
    size_t max_length = 0;
    for (const auto& line : lines) {
        if (line.length() > max_length) {
            max_length = line.length();
        }
    }

    // 프레임의 상단과 하단을 생성
    string border(max_length + 4, '*');
    framed.push_back(border);

    // 각 문자열을 프레임으로 둘러싸서 벡터에 추가
    for (const auto& line : lines) {
        framed.push_back("* " + line + std::string(max_length - line.length(), ' ') + " *");
    }

    // 프레임의 하단을 생성
    framed.push_back(border);

    return framed;
}

int main() {
    vector<string> lines;
    lines.push_back("this is an");
    lines.push_back("example");
    lines.push_back("to");
    lines.push_back("illustrate");
    lines.push_back("framing");

    // frame 함수 호출
    vector<string> result = frame(lines);

    // 프레임을 출력
    for (const auto& line : result) {
        cout << line << endl;
    }
    
    return 0;
}
