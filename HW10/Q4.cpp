class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int> > ans(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    mat[i][j] += mat[i][j-1];
                } else if (j == 0) {
                    mat[i][j] += mat[i-1][j];
                } else {
                    mat[i][j] += (mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1]);
                }
            }
        }
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                int r = (i + k < mat.size()) ? i + k : mat.size() - 1;
                int c = (j + k < mat[i].size()) ? j + k : mat[i].size() - 1;
                
                if (i-k <= 0 and j-k <= 0) {
                    ans[i][j] = mat[r][c];
                } else if (i-k <= 0) {
                    ans[i][j] = mat[r][c] - mat[r][j-k-1];
                } else if (j-k <= 0) {
                    ans[i][j] = mat[r][c] - mat[i-k-1][c];
                } else {
                    ans[i][j] = mat[r][c] - mat[i-k-1][c] - mat[r][j-k-1] + mat[i-k-1][j-k-1];
                }
            }
        }
        
        return ans;
    }
};