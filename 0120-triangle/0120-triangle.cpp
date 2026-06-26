class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, int n
    ,vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }

        int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
        int diag=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(down,diag);



    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return solve(0,0,triangle,n,dp); 
    }
};