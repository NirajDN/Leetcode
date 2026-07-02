class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int i=0;
        int j=col-1;

        while(i<row && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]<target){
                i++;
            }
            else j--;

        }
        return false;
    }
};