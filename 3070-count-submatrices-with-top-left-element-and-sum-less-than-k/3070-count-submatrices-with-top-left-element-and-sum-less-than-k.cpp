class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0; 

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i>0) grid[i][j] += grid[i-1][j];
                if(j>0) grid[i][j] += grid[i][j-1];
                if(i>0 && j>0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) res++;
                else break;
            }
        }

        return res; 
    }
};