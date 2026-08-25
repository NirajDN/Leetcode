class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        uint64_t x[2] = {0, 0};
        for (auto& n : nums)
            if (n % k == 0) {
                int i = n / k - 1;
                x[i >> 6] |= 1ULL << (i & 63);
            }

        int z = x[0] == -1ULL;
        return (z * 64 + bit_width(++x[z] & -x[z])) * k;
    }
};