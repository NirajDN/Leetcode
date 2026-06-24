class Solution {
public:

    int binary(vector<int>&nums,int target,int st,int en){
        if(st<=en){
            int mid=st+(en-st)/2;

            if(nums[mid]==target) return mid;

            if(nums[mid]<target){
                return binary(nums,target,mid+1,en);
            }
            else{
                return binary(nums,target,st,mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(nums,target,0,n-1);
    }
};