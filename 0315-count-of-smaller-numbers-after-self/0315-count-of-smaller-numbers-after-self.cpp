class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sortedList;
        vector<int> counts(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            // Find position to insert nums[i]
            int pos = lower_bound(sortedList.begin(), sortedList.end(), nums[i]) - sortedList.begin();
            counts[i] = pos;
            sortedList.insert(sortedList.begin() + pos, nums[i]);
        }

        return counts;
    }
};
