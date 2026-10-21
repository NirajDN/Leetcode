class Solution {
public:
    int minOperations(auto& s) {
        int n = s.length();
        char mn = s[0], mx = s[0];
        bool isSorted = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) isSorted = 0;
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
        }

        if (isSorted) return 0;
        if (n == 2) return -1;
        if (s.front() == mn || s.back() == mx)
            return 1;

        for (int i = 1; i < n - 1; i++)
            if (s[i] == mn || s[i] == mx)
                return 2;

        return 3;
    }
};