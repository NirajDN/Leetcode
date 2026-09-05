class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxSoFar = -1;
        int cand = 0, cmax = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (i == cand) cmax = maxSoFar;

            if (nums[i] < cmax - k)
                cand = i + 1;
        }

        return cand < nums.size() ? cand : -1;
    }
};