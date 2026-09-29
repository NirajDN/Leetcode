class Solution {
public:
    bool hasValidPath(auto& A) {
        int m = A.size(), n = A[0].size();

        if ((m + n - 1) & 1 || (A[0][0] & 1))
            return 0;

        vector dp(m + 1, vector<unordered_set<int>>(n + 1));
        dp[0][0].insert(0);

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                int v = 1 - ((A[i][j] & 1) << 1);

                for (auto& d : dp[i][j]) {
                    int nk = d + v;

                    if (nk > -1) {
                        dp[i + 1][j].insert(nk);
                        dp[i][j + 1].insert(nk);
                    }
                }
            }        

        return dp[m][n - 1].count(0);
    }
};