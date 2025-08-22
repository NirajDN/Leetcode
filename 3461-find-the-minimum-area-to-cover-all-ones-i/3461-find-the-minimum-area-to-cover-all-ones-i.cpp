class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int l = INT_MAX, u = INT_MAX;
        int r = INT_MIN, d = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    u = min(u, i);
                    r = max(r, j);
                    d = max(d, i);
                }
            }
        }

        return (r - l + 1) * (d - u + 1);
    }
};