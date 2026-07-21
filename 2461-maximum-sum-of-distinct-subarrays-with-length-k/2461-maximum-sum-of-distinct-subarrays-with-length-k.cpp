class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        long long sum = 0;
        long long maxSum = 0;
         for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }

        if (mp.size() == k) {
            maxSum = sum;
        }

        for (int i = k; i < n; i++) {
            sum -= nums[i - k];
            mp[nums[i - k]]--;

            if (mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
            sum += nums[i];
            mp[nums[i]]++;
            if (mp.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};