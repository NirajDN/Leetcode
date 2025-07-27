class Solution {
    public int maxSubArray(int[] nums) {
        int n=nums.length;
        int max=0;
        int k=nums[0];
        for(int i=0;i<n;i++){
            max+=nums[i];
            if(max>k){
                k=max;
            }
            if(max<0){
                max=0;
            }
        }
        return k;
    }
}