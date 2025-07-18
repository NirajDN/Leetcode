class Solution {
public:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return true;
                num /= 10;
            }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n;i++) {
            int j = n - i;
            if (!hasZero(i) && !hasZero(j))
                return {i, j};
        }
        return {}; 
    }
};
