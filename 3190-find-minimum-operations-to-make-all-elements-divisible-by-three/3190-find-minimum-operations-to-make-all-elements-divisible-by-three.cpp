class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int x=nums.size();
        for(int i=0;i<nums.size();x-=((nums[i++]%3==0))); return x;
    }
};