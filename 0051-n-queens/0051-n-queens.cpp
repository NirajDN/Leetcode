class Solution {
public:

    void findQueenPos(vector<string>& board, vector<vector<string>>& result, 
                      vector<int>& cols, vector<int>& df, vector<int>& db, 
                      int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = col - row + n - 1;
            int d2 = row + col;

            if (cols[col] == 0 && df[d1] == 0 && db[d2] == 0) {
                board[row][col] = 'Q';
                cols[col] = df[d1] = db[d2] = 1;

                findQueenPos(board, result, cols, df, db, row + 1, n);

                board[row][col] = '.';
                cols[col] = df[d1] = db[d2] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0);
        vector<int> df(2 * n - 1, 0);
        vector<int> db(2 * n - 1, 0);

        findQueenPos(board, result, cols, df, db, 0, n);
        return result;
    }
};
