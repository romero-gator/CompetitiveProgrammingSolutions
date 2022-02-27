#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1], dp[3][n+1];
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[0][i] = dp[1][i] = dp[2][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1 + min(dp[0][i-1], min(dp[1][i-1], dp[2][i-1]));

        if (arr[i] == 1 || arr[i] == 3) {
            dp[1][i] = min(dp[0][i-1], dp[2][i-1]);
        } else {
            dp[1][i] = INT_MAX;
        }

        if (arr[i] == 2 || arr[i] == 3) {
            dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
        } else {
            dp[2][i] = INT_MAX;
        }
    }

    int ans = min(dp[0][n], min(dp[1][n], dp[2][n]));
    cout << ans << endl;

    return 0;
}