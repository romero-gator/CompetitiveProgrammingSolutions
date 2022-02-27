#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    string line;
    set<string> collection;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        while (ss >> s) {
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        temp += tolower(s[i]);
                    } else {
                        temp += s[i];
                    }
                } else {
                    if (!temp.empty()) {
                        collection.insert(temp);
                    }
                    temp = "";
                }
            }
            if (!temp.empty()) {
                collection.insert(temp);
            }
        }
    }
    
    for (set<string>::iterator itr = collection.begin(); itr != collection.end(); itr++) {
        cout << *itr << endl;
    }

    return 0;
}