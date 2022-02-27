#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

string s, t;
int dp[1005][1005];

void printAns(int i, int j, int remain) {
    if (remain == 0) {
        return;
    }

    if (i > 0 && j > 0 && dp[i - 1][j - 1] + (int)(s[i-1] != t[j-1]) == dp[i][j]) {
        printAns(i - 1, j - 1, remain -  (int)(s[i-1] != t[j-1]));
        if (s[i-1] != t[j-1]) {
            cout << "REPLACE " << j << " " << t[j-1] << endl;
        }
    } else if (i > 0 && dp[i - 1][j] + 1 == dp[i][j]) {
        printAns(i - 1, j, remain - 1);
        cout << "DELETE " << j + 1 << endl;
    } else if (j > 0 && dp[i][j - 1] + 1 == dp[i][j]) {
        printAns(i, j - 1, remain - 1);
        cout << "INSERT " << j << " " << t[j-1] << endl;
    }
}

int main() {
    cin >> s >> t;

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= t.size(); i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= s.size(); i++){
        for (int j = 1; j <= t.size(); j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (int)(s[i-1] != t[j-1]));
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }    

    cout << dp[s.size()][t.size()] << endl;
    printAns(s.size(), t.size(), dp[s.size()][t.size()]);
}