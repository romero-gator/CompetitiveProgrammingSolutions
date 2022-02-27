#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main () {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        stack<char> s;
        bool valid = true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else if (str[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    valid = false;
                    break;
                } else {
                    s.pop();
                }
            } else if (str[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    valid = false;
                    break;
                } else {
                    s.pop();
                }
            } 
        }

        if (!valid || !s.empty()) {
            cout << "No" <<endl;
        } else {
            cout << "Yes" <<endl;
        }
    }

    return 0;
}