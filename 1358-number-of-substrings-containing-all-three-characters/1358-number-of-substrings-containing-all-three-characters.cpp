class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int p[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); i++) {
            p[(s[i] & 31) - 1] = i;
            res += min({p[0], p[1], p[2]}) + 1;
        }

        return res;
    }
};