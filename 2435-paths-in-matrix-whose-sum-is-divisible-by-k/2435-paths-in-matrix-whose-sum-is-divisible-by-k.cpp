class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        long long dp[n][m][k];
        for(int i = 0; i < k; i++) dp[0][0][i] = 0;
        dp[0][0][grid[0][0]%k] = 1;
        const int MOD =1000000007;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] %= k;
            }
        }
        for(int i = 1; i< n; i ++){
            for(int j = 0; j < k; j++){
                dp[i][0][j] = dp[i-1][0][(j-grid[i][0]+k)%k];
            }
        }        
        for(int i = 1; i< m; i ++){
            for(int j = 0; j < k; j++){
                dp[0][i][j] = dp[0][i-1][(j-grid[0][i]+k)%k];
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                for(int l = 0; l < k; l++){
                    dp[i][j][l] = 
                        (dp[i-1][j][(l-grid[i][j]+k)%k] + 
                         dp[i][j-1][(l-grid[i][j]+k)%k]
                        ) % MOD;
                }
            }
        }
        return dp[n-1][m-1][0];
        
    }
};