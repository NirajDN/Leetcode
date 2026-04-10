class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int last2[100] = {};
        int res = 200;

        for (int i = 0; i < n; i++) {
            int val = nums[i] - 1, pos = i + 1;
            int pack = last2[val];
            int old = pack & 255, cur = pack >> 8;

            last2[val] = cur | (pos << 8);

            if (old) res = min(res, (pos - old) << 1);
        }

        return -(res == 200) | res;
    }
};