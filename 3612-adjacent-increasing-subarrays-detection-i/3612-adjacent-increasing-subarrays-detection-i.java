class Solution {
        public boolean hasIncreasingSubarrays(List<Integer> A, int k) {
        int n = A.size(), up = 1, pre_max_up = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (A.get(i) > A.get(i - 1)) {
                up++;
            } else {
                pre_max_up = up;
                up = 1;
            }
            res = Math.max(res, Math.max(up / 2, Math.min(pre_max_up, up)));
        }
        return res >= k;
    }
}