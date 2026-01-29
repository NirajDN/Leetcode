class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum1=nums[n-3]*nums[n-2]*nums[n-1];
        int sum2=nums[0]*nums[1]*nums[n-1];   
        int maxSum;
        maxSum=max(sum1,sum2);
        return maxSum;  
    }
};