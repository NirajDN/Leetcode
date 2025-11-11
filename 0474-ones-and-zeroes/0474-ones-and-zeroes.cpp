class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(string str : strs){
        int one = 0;
        int zero = 0;
        for(char c : str){
            if(c == '1')
                one++;
            else
                zero++;
        }
        for(int i = m; i >= zero; i--){
            for(int j = n; j >= one; j--){
                if(one <= j && zero <= i)
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }
    return dp[m][n];
}
};