class Solution {
public:
    bool predictTheWinner(vector<int>& A) {
        int n = A.size();
        if (~n & 1) return true;

        vector dp(n, vector<int>(n, -1));
        auto maxDiff = [&](this auto&& maxDiff, int i, int j) -> int {
            int& res = dp[i][j];
            if (res != -1) return res;
            if (i == j) return res = A[i];

            return res = max(A[i] - maxDiff(i + 1, j),
                             A[j] - maxDiff(i, j - 1));
        };

        return maxDiff(0, n - 1) >= 0;
    }
};