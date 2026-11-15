class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 0, ans = 0;

        for (int x : arr) {
            if (x % 2 == 1) {
                long long newOdd = even + 1;
                long long newEven = odd;
                odd = newOdd;
                even = newEven;
            } else {
                even = even + 1;
            }
            ans = (ans + odd) % MOD;
        }

        return (int) ans;
    }
};