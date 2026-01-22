class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
        }
      if(count>0){
        return true;
      }  
      else{
        return false;
      }
    }
};