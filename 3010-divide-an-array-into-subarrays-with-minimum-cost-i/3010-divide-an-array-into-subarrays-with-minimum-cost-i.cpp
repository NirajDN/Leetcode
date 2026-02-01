class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n =nums.size();
        int minSum=INT_MAX;
        for(int i=1;i<n-1;i++){
            int sum=0;
            for(int j=i+1;j<n;j++){
                int sum=nums[0]+nums[i]+nums[j];
                minSum=min(sum,minSum);
            }
        }
        return minSum;
    }
};