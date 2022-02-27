#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == '<') { 
            s.pop();
        } else {
            s.push(str.at(i));
        }
    }

    string ans;
    while (!s.empty()) {
        char c = s.top();
        s.pop();
        ans.push_back(c);
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}