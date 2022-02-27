#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n; 
    cin >> n;
    
    int cars[2010];
    for (int i = 1; i <= n; i++) {
        cin >> cars[i];
    }

    int dp1[2010], dp2[2010], ans = 0;
    for (int i = n; i >= 1; i--) {
        dp1[i] = 1;
        dp2[i] = 1;
        for (int j = n; j > i; j--) {
            if (cars[i] > cars[j]) {
                dp1[i] = max(dp1[i], 1 + dp1[j]);
            } else {
                dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans << endl;

    return 0;
}