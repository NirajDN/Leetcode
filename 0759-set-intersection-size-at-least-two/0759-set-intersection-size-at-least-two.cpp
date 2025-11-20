class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &x, auto &y) { if (x[1] == y[1]) return x[0] > y[0]; return x[1] < y[1]; });

        int ans = 0;
        int a = -1, b = -1;

        for (auto &it : intervals) {
            int l = it[0], r = it[1];

            if (l > b) {
                a = r - 1;
                b = r;
                ans += 2;
            } else if (l > a) {
                a = b;
                b = r;
                ans += 1;
            }
        }
        return ans;
    }
};