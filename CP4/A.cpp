#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;
    int arr[n+1], dp[n+1];
    int ans = 0, lastNum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        m[arr[i]] = m[arr[i] - 1] + 1;
        if (m[arr[i]] > ans) {
            ans = m[arr[i]];
            lastNum = arr[i];
        }
    }
    cout << ans << endl;
    
    int temp = lastNum - ans + 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == temp) {
            cout << i << " ";
            temp++;
        }
    }

    return 0;
}