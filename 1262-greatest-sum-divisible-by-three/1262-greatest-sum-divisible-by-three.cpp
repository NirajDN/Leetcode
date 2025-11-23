class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        int min1 = INT_MAX, min2 = INT_MAX;
        int min11 = INT_MAX, min22 = INT_MAX;

        for (int x : nums) {
            sum += x;
            int r = x % 3;

            if (r == 1) {
                if (x < min1) { min11 = min1; min1 = x; }
                else if (x < min11) min11 = x;
            } else if (r == 2) {
                if (x < min2) { min22 = min2; min2 = x; }
                else if (x < min22) min22 = x;
            }
        }

        int rem = sum % 3;

        if (rem == 0) return sum;

        if (rem == 1) {
            int r1 = min1;
            int r2 = (min2 == INT_MAX || min22 == INT_MAX) ? INT_MAX : min2 + min22;
            int remove = min(r1, r2);
            return remove == INT_MAX ? 0 : sum - remove;
        } else {
            int r1 = min2;
            int r2 = (min1 == INT_MAX || min11 == INT_MAX) ? INT_MAX : min1 + min11;
            int remove = min(r1, r2);
            return remove == INT_MAX ? 0 : sum - remove;
        }
    }
};