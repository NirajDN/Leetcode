class Solution {
public:
    string longestPrefix(string &s) {
    vector<int> dp(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[j])
            dp[i] = ++j;
        else if (j > 0) {
            j = dp[j - 1];
            --i;
        }
    }
    return s.substr(0, j);
}
};