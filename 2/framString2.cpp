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

    const int pad = 1;
    const string greeting = "안녕하세요, " + name + "!";
    const int rows = 3 + 2 * pad;
    const int cols = greeting.size() + 2 + 2 * pad;

    for (int r = 0; r < rows; r++) {
        int c = 0;
        while (c < cols) {
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                cout << "*";
            } else if (r == pad && c == pad) {
                cout << greeting;
                c += greeting.size() - 1;
            } else {
                cout << " ";
            }
            c++;
        }
        cout << endl;
    }

    return 0;
}
