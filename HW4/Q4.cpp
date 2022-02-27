#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        int savings[n], index = -1, count = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp - x < 0) {
                index++;
            } else {
                count++;
            }
            savings[i] = temp - x;
        }

        sort(savings, savings + n);
        
        int j = n - 1;
        while (index >= 0 && savings[j] > 0) {
            if ((-1) * (savings[index]) < savings[j]) {
                savings[j] = savings[j] + savings[index];
                savings[index] = 0;
                count++;
                index--;
            } else if ((-1) * (savings[index]) > savings[j]) {
                savings[index] = savings[index] + savings[j];
                savings[j] = 0;
                j--;
            } else {
                savings[j] = 0;
                savings[index] = 0;
                count++;
                index--;
                j--;
            }
        }
        
        cout << count << endl;
    }

    return 0;
}