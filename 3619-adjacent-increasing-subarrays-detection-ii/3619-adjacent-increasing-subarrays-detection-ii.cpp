class Solution {
public:
        int maxIncreasingSubarrays(vector<int>& A) {
        int n = A.size(), up = 1, pre_max_up = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                up++;
            } else {
                pre_max_up = up;
                up = 1;
            }
            res = max({res, up / 2, min(pre_max_up, up)});
        }
        return res;
    }
};