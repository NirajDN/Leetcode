class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        long long steps=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int need=nums[i-1]+1-nums[i];
                steps+=need;
                nums[i]=nums[i-1]+1;
            }
        }
        return steps;
    }
};