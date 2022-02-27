#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < p.size() && p[i] == '*'; ++i) {
            dp[i + 1] = true;
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            dp[0] = false;
            bool a = (i == 1);
            for (int j = 1; j <= p.size(); ++j) {
                bool b = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = b || dp[j - 1];
                } else {
                    dp[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && a;
                }
                a = b;
            }
        }

        return dp[p.size()];
    }
};