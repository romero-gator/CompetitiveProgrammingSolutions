#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[n];
    fill(dp, dp+n, INT_MAX);

    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp+n, arr[i]) = arr[i];
    }
    int ans = (lower_bound(dp, dp + n, INT_MAX) - dp);
    cout << ans << endl;

    return 0;
}