class Solution {
public:
    int solve(int i, int j, int m, int n, string s1, string s2,
              vector<vector<int>>& dp) {

        vector<int> prev(n, 0), curr(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (s1[i] == s2[j]) {

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

        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int m = s1.size();
        int n = s2.size();

        if (m == 0) return 0;

        int i = m - 1;
        int j = n - 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(i, j, m, n, s1, s2, dp);
    }
};