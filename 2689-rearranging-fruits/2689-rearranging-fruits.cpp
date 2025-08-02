class Solution {
public:
   long long minCost(vector<int>& b1, vector<int>& b2) {
    map<int, long long> m;
    for (auto c : b1)
        ++m[c];
    for (auto c : b2)
        --m[c];
    long long swaps = 0, res = 0;
    for (auto [c, cnt] : m) {
        if (cnt % 2)
            return -1;
        swaps += max(0LL, cnt / 2);
    }
    for (auto [c, cnt] : m) {
        long long take = min(swaps, abs(cnt) / 2);
        res += take * min(c, begin(m)->first * 2);
        swaps -= take;
    }
    return res;
}
};