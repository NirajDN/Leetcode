class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int neg=1; 
        int pos=1;
        neg=nums[0]*nums[1]*nums[n-1];
        pos=nums[n-3]*nums[n-2]*nums[n-1];
        
        return (pos>neg)? pos:neg;
    }
};