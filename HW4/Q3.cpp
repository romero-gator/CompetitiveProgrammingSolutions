#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char c[100000];
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        int zeroes = 0, j = n - 1;
        for (int i = 0; i < n; i++) {
            if (c[i] == '0') {
                zeroes++;
            } else {
                j = i;
                break;
            }
        }

        int ones = 0;
        for (int i = n -1; i >= j; i--) {
            if (c[i] == '1') {
                ones++;
            } else {
                if (i > j) {
                    zeroes++;
                }
                break;
            }
        }

        for (int i = 0; i < zeroes; i++) {
            cout << '0';
        }
        for (int i = 0; i < ones; i++) {
            cout << '1';
        }
        cout << endl;
    }

    return 0;
}