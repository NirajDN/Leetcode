class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++) {
            int min = nums[i];
            int max = nums[n - 1 - i];
            if (min > max) swap(min, max);

            delta[2] += 2;
            delta[min + 1]--;
            delta[min + max]--;
            delta[min + max + 1]++;
            delta[max + limit + 1]++;
        }

        int res = n, moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};