class Solution {
public:
    int solve(int i, int j,int m, int n, string text1, string text2
    ,vector<vector<int>>&dp){
        
        int text1_out=0;
        int text2_out=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i<0 || j<0){
                    return 0;
                }
                if(text1[i]==text2[j]){
                    int a=0;
                    if(i>0 && j>0){
                     a=dp[i-1][j-1];
                    }
                    dp[i][j]=1+a;
                }
                else{
                    int b=0,c=0;
                    if(i>0){
                        b=dp[i-1][j];
                    }
                    if(j>0){
                        c=dp[i][j-1];
                    }
                     dp[i][j]=0+max(b,c);
                    }   
                    }
                }
                return dp[m-1][n-1];


    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n= text2.size();
        int i=m-1;
        int j=n-1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(i,j,m,n,text1,text2,dp);
        

}
};