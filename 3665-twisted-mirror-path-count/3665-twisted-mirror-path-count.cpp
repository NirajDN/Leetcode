class Solution {
    static constexpr int mat[2][2][2] = {{{1, 1}, {1, 1}}, {{0, 1}, {1, 0}}};
    static constexpr int MOD = 1000000007;

public:
    int uniquePaths(auto& A) {
        int n = A[0].size(), left = 0;
        vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 0; i < A.size(); i++) {
            left = 0;
            for (int j = 0; j < n; j++) {
                int c = A[i][j], top = dp[j];

                dp[j] = (left * mat[c][1][0] + top * mat[c][1][1]) % MOD;
                left  = (left * mat[c][0][0] + top * mat[c][0][1]) % MOD;
            }
        }

        return left;
    }
};