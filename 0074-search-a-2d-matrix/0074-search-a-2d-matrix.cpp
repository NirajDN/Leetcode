class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0){
            int currNum=matrix[i][j];
            if(currNum>target){
                j--;
            }
            else if(currNum<target){
                i++;
            }
            else return true;

        }
        return false;
    }
};