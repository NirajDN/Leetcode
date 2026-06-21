constexpr int M = 1e5 + 1;
int freq[M];
class Solution {
public:
    static int maxIceCream(vector<int>& costs, int coins) {
        int xMax = 0;
        for (int x : costs) {
            freq[x]++;
            xMax = max(xMax, x);
        }
        int cnt = 0;
        for (int x = 1; x <= xMax; x++) {
            const int f = freq[x];
            if (f == 0)
                continue;
            int buy = min(coins / x, f);
            if (buy == 0)
                break;
            cnt += buy;
            coins -= buy * x;
        }
        // reset for the next testcase
        for (int x : costs)
            freq[x] = 0;
        return cnt;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();