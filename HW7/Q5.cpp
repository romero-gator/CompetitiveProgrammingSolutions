class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        for (int i = 0; i < matrix.size(); i++)
        {
            dp[0][i] = matrix[0][i];
        }

        int temp1;
        int temp2;

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                if (j - 1 >= 0)
                {
                    temp1 = dp[i - 1][j - 1];
                }
                else
                {
                    temp1 = INT_MAX;
                }
                if (j + 1 < matrix.size())
                {
                    temp2 = dp[i - 1][j + 1];
                }
                else
                {
                    temp2 = INT_MAX;
                }
                dp[i][j] = min({temp1, temp2, dp[i - 1][j]}) + matrix[i][j];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
        {
            res = min(res, *min_element(begin(dp[matrix.size() - 1]), end(dp[matrix.size() - 1])));
        }
        return res;
    }
};