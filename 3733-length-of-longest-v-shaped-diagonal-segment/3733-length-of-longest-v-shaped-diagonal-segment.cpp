class Solution {
public:
    int dr[4] = {-1, 1, 1, -1};
    int dc[4] = {1, 1, -1, -1};

    vector<vector<vector<vector<int>>>> memo;
    int n, m;

    bool inBounds(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int dfs(vector<vector<int>>& grid, int r, int c, int dir, bool canChange) {
        int canChange_idx = canChange ? 1 : 0;
        
        if (memo[r][c][dir][canChange_idx] != -1) {
            return memo[r][c][dir][canChange_idx];
        }

        int searchFor = (grid[r][c] == 2) ? 0 : 2;
        int maxi = 1;

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (inBounds(nr, nc) && grid[nr][nc] == searchFor) {
            maxi = max(maxi, 1 + dfs(grid, nr, nc, dir, canChange));
        }

        if (canChange) {
            int ndir = (dir + 1) % 4;
            nr = r + dr[ndir];
            nc = c + dc[ndir];
            if (inBounds(nr, nc) && grid[nr][nc] == searchFor) {
                maxi = max(maxi, 1 + dfs(grid, nr, nc, ndir, false));
            }
        }

        return memo[r][c][dir][canChange_idx] = maxi;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        
        int maxi = 0;
        
        memo.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, 1);
                    
                    for (int d = 0; d < 4; d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];

                        if (inBounds(nr, nc) && grid[nr][nc] == 2) {
                            maxi = max(maxi, 1 + dfs(grid, nr, nc, d, true));
                        }
                    }
                }
            }
        }
        return maxi;
    }
};