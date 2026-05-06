class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();       // rows
        int m = box[0].size();    // cols

        vector<vector<char>> result(m, vector<char>(n, '.'));

        for (int i = 0; i < n; i++) {
            int lastEmpty = m - 1;

            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    result[j][n - i - 1] = '*';
                    lastEmpty = j - 1;
                }
                else if (box[i][j] == '#') {
                    result[lastEmpty][n - i - 1] = '#';
                    lastEmpty--;
                }
            }
        }

        return result;
    }
};