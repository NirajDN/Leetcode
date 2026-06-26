class Solution {
public:

    int calc(int i, int j,int r, int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
         dp[0][0]=grid[0][0];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 &&j==0){
                    dp[0][0]=grid[0][0];
                }
                else{
                int up=1e9;
                int lef=1e9;
                if(i>0){
                up=grid[i][j]+dp[i-1][j];
                }
                if(j>0){
                lef=grid[i][j]+dp[i][j-1];
                } 
                dp[i][j]=min(up,lef);
                }
            }
        }
        return dp[r-1][c-1];

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