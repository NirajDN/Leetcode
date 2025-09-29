class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        int dp[50][50] = {};
        for (int sz = 2; sz < n; sz++) {
            for (int i = 0; i + sz < n; i++) {
                int j = i + sz;
                dp[i][j] = 1e9;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], A[i]*A[j]*A[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};