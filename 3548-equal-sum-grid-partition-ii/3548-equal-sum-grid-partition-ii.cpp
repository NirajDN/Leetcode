class Solution {
public:
    typedef long long ll;
    bool solve(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        ll bottomSum=0,topSum=0;
        vector<int>bottomFreq(100001,0),topFreq(100001,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bottomSum+=grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }
        for(int i=0;i<n-1;i++){
           for(int j=0;j<m;j++){
                bottomSum-=grid[i][j];
                bottomFreq[grid[i][j]]--;
                topSum+=grid[i][j];
                topFreq[grid[i][j]]++;
           }
           if(topSum==bottomSum)return true;
           ll diffTop=topSum-bottomSum;
           if(diffTop>0 && diffTop<=100000){
              int h=i+1,w=m;
              if(h>1 && w>1){
                if(topFreq[diffTop])return true;
                }
                else if(h>1 && w==1){
                    if(grid[0][0]==diffTop || grid[i][0]==diffTop)return true;
                }else if(h==1 && w>1){
                    if(grid[0][0]==diffTop || grid[0][w-1]==diffTop)return true;
                }
           }
           ll diffBot=bottomSum-topSum;
           if(diffBot>0 && diffBot<=100000){
            int h=(n-i-1),w=m;
            if(h>1 && w>1){
                if(bottomFreq[diffBot])return true;
            }else if(h>1 && w==1){
                if(grid[i+1][0]==diffBot || grid[n-1][0]==diffBot)return true;
            }else if(h==1 && w>1){
                if(grid[n-1][0]==diffBot || grid[n-1][w-1]==diffBot)return true;
            }
           }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid))return true;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j][i]=grid[i][j];
            }
        }
        return solve(mat);
    }
};