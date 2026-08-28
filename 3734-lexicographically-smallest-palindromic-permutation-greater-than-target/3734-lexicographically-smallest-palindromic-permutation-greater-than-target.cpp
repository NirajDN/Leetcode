class Solution {
public:
    string lexPalindromicPermutation(string str, string target) {
        int freq[26] = {0};
        for (char s : str)
            freq[s - 'a']++;

        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                if (center != 0)
                    return "";
                center = 'a' + i;
                freq[i]--;
            }
        }

        int sz = str.length();
        int half = sz / 2;
        for (int i = 0; i < half; i++)
            freq[target[i] - 'a'] -= 2;

        if (check(freq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            string tail = "";
            if (center != 0)
                tail += center;
            tail += rev;
            if (tail > target.substr(half))
                return head + tail;
        }

        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            freq[w - 'a'] += 2;
            if (!check(freq))
                continue;

            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j] -= 2;
                string result = target.substr(0, i + 1);
                result[i] = 'a' + j;

                for (int k = 0; k < 26; k++) {
                    int cnt = freq[k] / 2;
                    if (cnt > 0)
                        result.append(cnt, 'a' + k);
                }

                string part = result;
                reverse(part.begin(), part.end());
                if (center != 0)
                    result.push_back(center);
                result += part;
                return result;
            }
        }

        return "";
    }

    bool check(int f[]) {
        for (int i = 0; i < 26; i++)
            if (f[i] < 0)
                return false;
        return true;
    }
};