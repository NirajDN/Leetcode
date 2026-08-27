class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (int i = n - 1; i >= 0; i--) {
            vector<int> remain = cnt;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (remain[x] == 0) {
                    possible = false;
                    break;
                }

                remain[x]--;
            }

            if (!possible)
                continue;

            int targetChar = target[i] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {

                if (remain[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);

                remain[c]--;
                for (int x = 0; x < 26; x++) {
                    ans.append(remain[x], char('a' + x));
                }

                return ans;
            }
        }

        return "";
    }
};