#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], inc[n], dec[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    inc[0] = 1;
    for (int i = 1; i < n; i++) {
        inc[i] = 1;
        if (arr[i-1] < arr[i]) {
            inc[i] = inc[i-1] + 1;
        }
        ans = max(ans, inc[i]);
    }

    dec[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        dec[i] = 1;
        if (arr[i] < arr[i+1]) {
            dec[i] = dec[i+1] + 1;
        }
        ans = max(ans, dec[i]);
    }

    for (int i = 0; i < n-2; i++) {
        if (arr[i] < arr[i+2]) {
            ans = max(ans, inc[i] + dec[i+2]);
        }
    }

    cout << ans << endl;

    return 0;
}