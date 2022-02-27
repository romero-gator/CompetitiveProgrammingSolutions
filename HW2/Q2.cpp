#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    bool p1wins = false;
    stack<char> s;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (!s.empty()) {
            if (s.top() == str[i]) {
                s.pop();
                p1wins = !p1wins;
            } else {
                s.push(str[i]);
            }
        } else {
            s.push(str[i]);
        }
    }

    if (p1wins) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}