class Solution {
public:
    int scoreOfParentheses(string s) {
        return F(s, 0, s.length());
    }

private:
    int F(const string& s, int i, int j) {
        int ans = 0, bal = 0;
        for (int k = i; k < j; ++k) {
            bal += (s[k] == '(' ? 1 : -1);
            if (bal == 0) {
                if (k - i == 1) {
                    ans++;
                } else {
                    ans += 2 * F(s, i + 1, k);
                }
                i = k + 1;
            }
        }
        return ans;
    }
};