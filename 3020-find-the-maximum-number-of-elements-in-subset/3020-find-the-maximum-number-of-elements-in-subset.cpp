class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& n : nums)
            freq[n]++;

        int res = (freq[1] - 1) | 1;
        freq.erase(1);

        for (auto& f : freq) {
            int n = 0, x = f.first;

            int sq = sqrt(x);
            if (sq * sq == x && freq.count(sq) && freq[sq] > 1)
                continue;

            while (x < 31623 && freq.count(x) && freq[x] > 1) {
                n += 2;
                x *= x;
            }

            res = fmax(res, n + ((freq.count(x) << 1) - 1));
        }

        return res;
    }
};