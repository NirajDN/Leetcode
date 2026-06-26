class Solution {
public:

    int calc(int i, int j,int r, int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up=grid[i][j]+calc(i-1,j,r,c,grid,dp);
        int lef=grid[i][j]+calc(i,j-1,r,c,grid,dp);
        return dp[i][j]=min(up,lef);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();  
        int c = grid[0].size();     
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int i=r-1;
        int j=c-1;
        return calc(i,j,r,c,grid,dp);

    }
};