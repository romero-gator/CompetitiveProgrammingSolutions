#include <iostream>
#include <string>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        long long max = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                bool check = true;
                long long count = 0;
                for (long long k = 0; k < s.size(); k++) {
                    if (check && s[k] == (48+i)) {
                        count++;
                        check = !check;
                    } else if (!check && s[k] == (48+j)) {
                        count++;
                        check = !check;
                    }
                }

                if (i != j) {
                    count -= (count % 2);
                }

                if (count > max) {
                    max = count;
                }
            }
        }

        cout << (s.size() - max) << endl;
    }

    return 0;
}