class Solution {
public:
    int solve(int i,int n,vector<int> & dp){
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
        int oc=dp[i+1];
        int tc=dp[i+2];
        dp[i]=oc+tc;
        }
        return dp[0];
    }
    int climbStairs(int n) {
        vector<int> dp(n+2,0);
        return solve(0,n,dp);
        
    }
};