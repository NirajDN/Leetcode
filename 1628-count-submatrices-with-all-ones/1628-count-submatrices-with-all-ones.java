class Solution {
        public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length, height[] = new int[n], res = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[j] = mat[i][j] == 0 ? 0 : height[j] + 1;
                for (int k = j, min = height[j]; k >= 0 && min > 0; k--) {
                    min = Math.min(min, height[k]);
                    res += min;
                }
            }
        }
        return res;
    }
}