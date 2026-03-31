class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?'); // ? indicates an undecided position

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            // The substring must equal t
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a'; // Initial value for undecided positions is a
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            // Find the last undecided position
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') { // Previously filled with a, now change it to b
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};