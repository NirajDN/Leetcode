class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> d(100001, 0);
        long long k = (long long)k1 + k2, sum = 0;
        int mx = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            d[x]++;
            sum += x;
            mx = max(mx, x);
        }
        if (sum <= k) return 0;
        for (int i = mx; i > 0 && k > 0; i--) {
            long long move = min(k, (long long)d[i]);
            d[i] -= move;
            d[i - 1] += move;
            k -= move;
        }
        long long ans = 0;
        for (int i = 0; i <= mx; i++)
            ans += (long long)i * i * d[i];

        return ans;
    }
};