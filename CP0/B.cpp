#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    bool openquote = true;

    while (getline(cin, str)) {
        while (str.find('"') != string::npos) {
           if (openquote) {
                size_t pos = str.find('"');
                str.replace(pos, 1, "``");
                openquote = false;
            } else {
                size_t pos = str.find('"');
                str.replace(pos, 1, "''");
                openquote = true;
            } 
        }
        cout << str << endl;
    }

    return 0;
}