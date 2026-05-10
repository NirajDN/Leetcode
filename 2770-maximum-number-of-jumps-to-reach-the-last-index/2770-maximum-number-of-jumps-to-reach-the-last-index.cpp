class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp array to store max jumps till index i
        vector<int> dp(n, -1);

        // First index is reachable with 0 jumps
        dp[0]=0;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                // Check if the condition holds true and prev index was visited
                if(abs(nums[i]-nums[j]) <= target && dp[j]>-1) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        return dp[n-1];
    }
};