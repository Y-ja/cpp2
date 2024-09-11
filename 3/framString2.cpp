#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    cout << "이름을 입력하세요 -> ";
    string name;
    cin >> name;

    const int topBottomPadding = 1;  // 상하 공백 크기
    const int leftRightPadding = 4;  // 좌우 공백 크기

    const string greeting = "안녕하세요, " + name + "!";
    const int rows = 3 + 2 * topBottomPadding;
    const int cols = greeting.size() + 2 + 2 * leftRightPadding;

    for (int r = 0; r < rows; r++) {
        int c = 0;
        while (c < cols) {
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                cout << "*";
            } else if (r == topBottomPadding + 1 && c >= leftRightPadding && c < leftRightPadding + greeting.size()) {
                cout << greeting[c - leftRightPadding];
            } else {
                cout << " ";
            }
            c++;
        }
        cout << endl;
    }

    return 0;
}
