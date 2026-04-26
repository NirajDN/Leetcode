class Solution {
    static constexpr int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bitset<250005> visit;

        auto dfs = [&](this auto&& dfs, int r, int c, int pr, int pc) -> bool {
            visit[r * n + c] = 1;
            
            for (const auto& d : dirs) { 
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr != pr || nc != pc)// skip parent
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) // check if in bounds
                        if (grid[nr][nc] == grid[r][c]) // same char -> follow path
                            if (visit[nr * n + nc] || dfs(nr, nc, r, c))
                                return true;
            }
            return false;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visit[i * n + j] && dfs(i, j, -1, -1))
                    return true;
        return false;
    }
};