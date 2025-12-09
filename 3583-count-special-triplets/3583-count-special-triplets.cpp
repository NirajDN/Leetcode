const int MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> r, l;
        for (int val : nums) {
            r[val]++;
        }

        for (int j = 0; j < n; ++j) {
            int mid = nums[j];
            r[mid]--; 
            int left = l[2 * mid];
            int right = r[2 * mid];
            result = (result + 1LL * left * right) % MOD;
            l[mid]++;
        }

        return result;
    }
};