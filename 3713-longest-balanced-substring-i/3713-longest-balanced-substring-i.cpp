class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
            a[i] = s[i] - 'a';

        int result = 0;
        for (int l = 0; l < n; ++l) {
            if (n - l <= result) 
                break;
            int cnt[26] = {0};         
            int uniq = 0, maxfreq = 0;  
            for (int r = l; r < n; ++r) {
                int i = a[r];
                if (cnt[i] == 0) 
                    ++uniq;
                ++cnt[i];
                if (cnt[i] > maxfreq) 
                    maxfreq = cnt[i];
                int cur = r - l + 1;
                if (uniq * maxfreq == cur && cur > result)
                    result = cur;
            }
        }
        return result;
    }
};