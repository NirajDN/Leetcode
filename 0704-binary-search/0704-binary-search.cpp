class Solution {
public:
    int binary(vector<int> &nums, int target, int n, int st,int end){
        if(st<=end){
            int mid=st+(end-st)/2;

            if(nums[mid]==target) return mid;

            if(nums[mid]<target){
                return binary(nums,target,n,mid+1,end);
            }

            if(nums[mid]>target){
                return binary(nums,target,n,st,mid-1);
            }

        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(nums,target,n,0,n-1);
    }
};