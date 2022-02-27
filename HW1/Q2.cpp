#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int numTests;
    cin >> numTests;
    while (numTests > 0) {
        int numDays;
        cin >> numDays;
        string str;
        cin >> str;

        set<char> s;
        bool suspicious = false;
        for (int i = 0; i < numDays; i++) {
            if (s.count(str.at(i)) > 0) {   
                if (str.at(i - 1) != str.at(i)) {
                    suspicious = true;
                    break;
                }
            } else {
                s.insert(str.at(i));
            }
        }
        
        if (suspicious) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        numTests--;
    }

    return 0;
}