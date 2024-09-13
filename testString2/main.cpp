#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// 주어진 문자열 벡터를 세로 방향으로 결합하는 함수
vector<string> vertical_cat(const vector<string>& lines) {
    vector<string> framed;
    if (lines.empty()) return framed;

    size_t max_length = 0;
    // 가장 긴 문자열의 길이를 찾기
    vector<string>::const_iterator it = lines.begin();
    while (it != lines.end()) {
        if (it->length() > max_length) max_length = it->length();
        ++it;
    }

    string border(max_length + 4, '*');
    framed.push_back(border);

    // 각 문자열을 세로로 결합하여 프레임으로 둘러싸기
    for (size_t i = 0; i < max_length; ++i) {
        string frame_line = "* ";
        it = lines.begin();
        while (it != lines.end()) {
            frame_line += (i < it->length()) ? (*it)[i] : ' ';
            ++it;
        }
        frame_line += " *";
        framed.push_back(frame_line);
    }

    framed.push_back(border);
    return framed;
}

// 주어진 문자열 벡터를 가로 방향으로 결합하는 함수
vector<string> horizontal_cat(const vector<string>& lines) {
    vector<string> framed;
    if (lines.empty()) return framed;

    string combined;
    // 문자열을 가로로 결합
    vector<string>::const_iterator it = lines.begin();
    while (it != lines.end()) {
        combined += *it + ' ';
        ++it;
    }

    string border(combined.length() + 4, '*');
    framed.push_back(border);
    framed.push_back("* " + combined + " *");
    framed.push_back(border);

    return framed;
}

int main() {
    vector<string> lines = {
        "this is an",
        "example",
        "to",
        "illustrate",
        "framing"
    };

    // vertical_cat 함수 호출 및 결과 출력
    vector<string> vertical_result = vertical_cat(lines);
    cout << "Vertical Frame:" << endl;
    vector<string>::const_iterator it = vertical_result.begin();
    while (it != vertical_result.end()) {
        cout << *it << endl;
        ++it;
    }

    cout << endl;

    // horizontal_cat 함수 호출 및 결과 출력
    vector<string> horizontal_result = horizontal_cat(lines);
    cout << "Horizontal Frame:" << endl;
    it = horizontal_result.begin();
    while (it != horizontal_result.end()) {
        cout << *it << endl;
        ++it;
    }

    return 0;
}
