#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n], max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    if (k == 1) {
        cout << min << endl;
    } else if (k == 2) {
        int ans = (arr[0] > arr[n-1]) ? arr[0] : arr[n-1];
        cout << ans << endl;
    } else {
        cout << max << endl;
    }

    return 0;
}