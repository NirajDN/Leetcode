class Solution {
public:
    int solve(int i, int j, int m, int n, string text1, string text2,
              vector<vector<int>>& dp) {

        vector<int> prev(n, 0), curr(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (text1[i] == text2[j]) {

                    int a = 0;
                    if (i > 0 && j > 0)
                        a = prev[j - 1];

                    curr[j] = 1 + a;
                }
                else {

                    int b = 0, c = 0;

                    if (i > 0)
                        b = prev[j];

                    if (j > 0)
                        c = curr[j - 1];

                    curr[j] = max(b, c);
                }
            }

            prev = curr;
        }

        return prev[n - 1];
    }

    int longestPalindromeSubseq(string s) {

        string text1 = s;
        string text2 = s;
        reverse(text2.begin(), text2.end());

        int m = text1.size();
        int n = text2.size();

        if (m == 0) return 0;

        int i = m - 1;
        int j = n - 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(i, j, m, n, text1, text2, dp);
    }
};