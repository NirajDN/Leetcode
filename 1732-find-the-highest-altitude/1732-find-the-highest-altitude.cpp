class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;

        for (auto& it : gain) {
            sum += it;
            int d = sum - ans;
            ans += d & ~(d >> 0x1F);
        }

        return ans;
    }
};