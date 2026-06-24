class Solution {
public:
    int climb(int i,int n,vector<int> &dp){
        if(i==n){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int oj=climb(i+1,n,dp);
        int tj=climb(i+2,n,dp);
        return dp[i]=oj+tj;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb(0,n,dp);
    }
};