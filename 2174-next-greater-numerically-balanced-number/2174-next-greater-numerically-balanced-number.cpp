class Solution {
    vector<int> count = {1, 2, 3, 4, 5, 6};
    int ans = 1224444;

    void check(int n, int cur) {
        if (cur >= 1224444)
            return;
        if (cur > n) {

            if ((count[0] == 0 || count[0] == 1) &&
                (count[1] == 0 || count[1] == 2) &&
                (count[2] == 0 || count[2] == 3) &&
                (count[3] == 0 || count[3] == 4) &&
                (count[4] == 0 || count[4] == 5) &&
                (count[5] == 0 || count[5] == 6)) {
                ans = min(ans, cur);
                return;
            }
        }

        for (int i = 0; i < 6; i++) {
            if (count[i] > 0) {
                count[i]--;
                check(n, cur * 10 + (i + 1));
                count[i]++;
            }
        }
    }

public:
    int nextBeautifulNumber(int n) {
        check(n, 0);
        return ans;
    }
};