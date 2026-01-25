class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1) return 0;
        int minDiff=nums[k-1]-nums[0];
        for(int i=1;i<=n-k;i++){
            int diff=nums[i+k-1]-nums[i];
            minDiff=min(diff,minDiff);
        }
        return minDiff;
    }
};