class Solution {
public:
    static constexpr int LIM = 1 << 10;
    int minCost(auto& A) {
        int m = A.size(), n = A[0].size();
        bitset<LIM> dp[n];
        
        dp[0].set(A[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j) continue;

                bitset<LIM> prev;
                if (i > 0) prev |= dp[j];
                if (j > 0) prev |= dp[j - 1];
                
                bitset<LIM> curr;
                for (int k = prev._Find_first(); k < LIM; k = prev._Find_next(k))
                    curr.set(k ^ A[i][j]);

                dp[j] = curr;
            }
        }

        return dp[n - 1]._Find_first();
    }
};