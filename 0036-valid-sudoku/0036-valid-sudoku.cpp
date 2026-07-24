class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                int box = (i / 3) * 3 + (j / 3);
                if(rows[i][num])
                    return false;
                if(cols[j][num])
                    return false;
                if(boxes[box][num])
                    return false;
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num]=true;
                
            }
        }
        return true;
    }
};