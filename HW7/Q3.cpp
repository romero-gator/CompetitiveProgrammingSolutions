#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    long long num;
    long long k;
    long long m;
    cin >> num;
    int dp[20][150][150];
    for (int i = 1; i < 101; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[1][j][i] = (((i * (1 + i)) - ((j - 1) * j)) / 2);
        }
    }
    int inter;
    for (int i = 2; i < 11; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            for (int k = j; k > 0; k--)
            {
                inter = INT_MAX;
                for (int l = k; l <= j; l++)
                {
                    inter = min(l + max(dp[i][l + 1][j], dp[i - 1][k][l - 1]), inter);
                }
                dp[i][k][j] = inter;
            }
        }
    }
    while (num--)
    {
        cin >> k >> m;
        cout << dp[k][1][m] << "\n";
    }
    return 0;
}