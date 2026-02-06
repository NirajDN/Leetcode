class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, maxSize = 0;

        for (int right = 0; right < n; ++right) {
            while ((long long)nums[right] > (long long)k * nums[left]) left++;
            maxSize = max(maxSize, right - left + 1);
        }
        return n - maxSize;
    }
};