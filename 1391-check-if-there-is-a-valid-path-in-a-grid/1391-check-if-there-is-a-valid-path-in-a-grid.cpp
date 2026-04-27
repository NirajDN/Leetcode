class Solution {
    static constexpr int TRANS[6][4] = {{-1, 1, -1, 3},
                                        {0, -1, 2, -1},
                                        {3, 2, -1, -1},
                                        {1, -1, -1, 2},
                                        {-1, 0, 3, -1},
                                        {-1, -1, 1, 0}};
    static constexpr int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static constexpr int START[6][2] = {{1, 3}, {0, 2}, {2, 3},
                                        {1, 2}, {0, 3}, {0, 1}};

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return true;

        auto check = [&](int di) -> bool {
            if (di == -1) return false;
            int r = DIRS[di][0];
            int c = DIRS[di][1];
            bitset<90000> visit;

            while (r >= 0 && r < m && c >= 0 && c < n) {
                int cell = r * n + c;
                if (visit[cell]) return false;
                visit[cell] = 1;

                di = TRANS[grid[r][c] - 1][di];
                if (di == -1) return false;
                if (r == m - 1 && c == n - 1) return true;

                r += DIRS[di][0];
                c += DIRS[di][1];
            }

            return false;
        };

        const int* s = START[grid[0][0] - 1];
        return check(s[0]) || check(s[1]);
    }
};