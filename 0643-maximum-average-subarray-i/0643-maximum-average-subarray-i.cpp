class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double totalSum=0;
        for(int i=0;i<k;i++){
            totalSum+=nums[i];
        }
        double avg = totalSum/k;
        double maxSum=totalSum;
        for(int i=k;i<n;i++){
            totalSum+=nums[i]-nums[i-k];
            maxSum=max(maxSum,totalSum);
            
        }
        return maxSum/k;
    }
};