using ll = long long;
class Solution {
    static inline int waves[570];
    static inline bool init = []() {
        int j = 0;
        for (int i = 0; i < 1000; i++) {
            int r = i % 10;
            int m = (i / 10) % 10;
            int l = (i / 100) % 10;
            if ((m > max(l, r)) | (m < min(l, r)))
                waves[j++] = i;
        }
        return 0;
    }();

public:
    ll totalWaviness(ll A, ll B) { return waveCount(B) - waveCount(A - 1); }

private:
    ll waveCount(ll num) {
        if (num < 100)
            return 0;
        ll res = 0;
        for (auto& p : waves)
            res += countWays(num, p);
        return res;
    }

    ll countWays(ll num, int pattern) {
        ll type = pattern < 100;
        ll count = 0, mult = 1;

        for (int i = 0; i < 16; i++) {
            if (mult * 100 > num)
                break;

            ll pre = num / (mult * 1000);
            ll cur = (num / mult) % 1000;
            ll suf = num % mult;

            ll ways = 0, edge = 0;

            if (cur > pattern)
                ways = pre - type + 1;
            else if (cur == pattern) {
                ways = max(0LL, pre - type);
                edge = suf + 1;
            } else if (cur < pattern)
                ways = max(0LL, pre - type);

            count += ways * mult + edge;
            mult *= 10;
        }

        return count;
    }
};