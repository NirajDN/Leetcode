class Solution {
public:
    int findMin(vector<int>& nums) {
        return *partition_point(nums.begin(), nums.end(), [&](int n) { return n > nums.back(); });
    }
};