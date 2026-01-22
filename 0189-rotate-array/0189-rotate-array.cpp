class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector <int> arr1;
        if(k>n){
            k=k%n;
        }
        if(k>0){
            arr1.push_back(nums[n-k]);
        }
        for(int i=n-k+1;i<n;i++){
            arr1.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            arr1.push_back(nums[i]);
        }
        nums=arr1;
    }
};