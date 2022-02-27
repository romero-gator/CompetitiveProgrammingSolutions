#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        size_t pos = str.find(' ');
        int t = stoi(str.substr(0, pos));
        int v = stoi(str.substr(pos, str.size() - 1));
        cout << (t*v*2) << endl;
    }

    return 0;
}