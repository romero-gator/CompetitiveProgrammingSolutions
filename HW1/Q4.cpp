#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        } else {
            int s, t1 = 0, t2, miles = 0;
            for (int i = 0; i < n; i++) {
                cin >> s;
                cin >> t2;
                miles += (t2 - t1) * s;
                t1 = t2;
            }
            cout << miles << " miles" << endl;
        }
    }

    return 0;
}