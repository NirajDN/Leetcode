
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = energy.size();
        vector<int> dp(n, 0);
        
        int res = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);

            if(dp[i] > res) {
                res = dp[i];
            }
        }
        
        return res;
    }
};