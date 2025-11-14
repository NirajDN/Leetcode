class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<int>row1,row2;
        vector<int>fir(n+1,0),sec(n+1,0);
        vector<vector<int>>ans(n,vector<int>(n+1,0));
        
        for(auto x : queries){
            int x1 = x[0], x2 = x[2];
            int y1 = x[1], y2 = x[3];
            
            for(int i = x1; i<=x2; i++){
                ans[i][y1] +=1;
                ans[i][y2+1] -=1;
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(j>0) ans[i][j] = ans[i][j]+ans[i][j-1];
            }
        }
        for(int i = 0; i<n; i++) ans[i].pop_back();

        return ans;
    }
};