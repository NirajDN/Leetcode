class Solution {
public:
    unordered_map<long long, int> cache;
    string s;
    int k;

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        return dp(0, 0, true) + 1;
    }

private:
    int dp(long long index, long long currentSet, bool canChange) {
        long long key = (index << 27) | (currentSet << 1) | canChange;

        if (cache.count(key)) {
            return cache[key];
        }

        if (index == s.size()) {
            return 0;
        }

        int characterIndex = s[index] - 'a';
        int currentSetUpdated = currentSet | (1 << characterIndex);
        int distinctCount = __builtin_popcount(currentSetUpdated);

        int res;
        if (distinctCount > k) {
            res = 1 + dp(index + 1, 1 << characterIndex, canChange);
        } else {
            res = dp(index + 1, currentSetUpdated, canChange);
        }

        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; ++newCharIndex) {
                int newSet = currentSet | (1 << newCharIndex);
                int newDistinctCount = __builtin_popcount(newSet);

                if (newDistinctCount > k) {
                    res = max(res, 1 + dp(index + 1, 1 << newCharIndex, false));
                } else {
                    res = max(res, dp(index + 1, newSet, false));
                }
            }
        }

        return cache[key] = res;
    }
};