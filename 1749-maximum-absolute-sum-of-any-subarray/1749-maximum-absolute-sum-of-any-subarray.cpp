class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int minSum=nums[0];
        int maxSum=0;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
             sum1=sum1+nums[i];
            maxSum=max(sum1,maxSum);
            if(sum1<0){
                sum1=0;
            }
        }
        for(int i=0;i<n;i++){
             sum2=sum2+nums[i];
            minSum=min(sum2,minSum);
            if(sum2>0){
                sum2=0;
            }
        }
        int k=max(maxSum,abs(minSum));
        return k; 
    }
};