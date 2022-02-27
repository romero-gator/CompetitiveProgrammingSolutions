#include <iostream>
#include <string>
using namespace std;

int main () {
    string line;
    cin >> line;

    int l = line.size() - 1, r = 0, arr[line.size()];
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == 'l') {
            arr[l] = i+1;
            l--;
        } else {
            arr[r] = i+1;
            r++;
        }
    }

    for (int i = 0; i < line.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}