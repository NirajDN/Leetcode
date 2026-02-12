class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        int leftSum=0;
        for(int x:nums){
            totalSum+=x;
        }
        for(int i=0;i<n;i++){
            if(leftSum==totalSum-leftSum-nums[i]){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};