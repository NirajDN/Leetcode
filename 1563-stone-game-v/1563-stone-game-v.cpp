int dp[501][501];
int Sum[501];
class Solution {
public:
    static int f(int l, int r){
        if (dp[l][r]!=-1)  return dp[l][r];
        int ans=0;
        for (int m=l; m<r; m++){
            int Lsum=Sum[m+1]-Sum[l], Rsum=Sum[r+1]-Sum[m+1];
            
            if (Lsum<=Rsum) ans=max(ans, Lsum+f(l, m));
            if (Lsum>=Rsum) ans=max(ans, Rsum+f(m+1, r));

            if (2*min(Lsum, Rsum)<=ans) break;
        }
        return dp[l][r]=ans;
    }

    static int stoneGameV(vector<int>& stoneValue) {
        const int n=stoneValue.size();
        partial_sum(stoneValue.begin(), stoneValue.end(), Sum+1);
        for(int i=0; i<=n; i++)
            memset(dp[i], -1, sizeof(int)*(n+1));
        return f(0, n-1);
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();