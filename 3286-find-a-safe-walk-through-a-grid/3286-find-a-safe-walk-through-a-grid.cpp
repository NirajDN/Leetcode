const int N=5000;
int q[N], front, back;// implement deque
int maxH[N];
int d[5]={0, 1, 0, -1, 0};
class Solution {
public:
    static inline int idx(int i, int j, int c){ return i*c+j; }
    static bool outSide(int i, int j, int r, int c){
        return i<0||i>=r||j<0||j>=c;
    }
    static bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int r=grid.size(), c=grid[0].size();
        memset(maxH, -1, r*c*sizeof(int));
        front=back=N/2;// reset q
        q[back++]=0; 
        maxH[0]=health-grid[0][0];
        while(front<back){
            int ij=q[front++];// pop front
            int curH=maxH[ij];
            if (ij==r*c-1) return curH>0;
            auto [i, j]=div(ij, c);
            for(int a=0; a<4; a++){
                const int s=i+d[a], t=j+d[a+1];
                if (outSide(s, t, r, c)) continue;
                const int st=idx(s,t, c);
                int H2=curH-grid[s][t];
                if(H2>maxH[st]){
                    maxH[st]=H2;
                    if (grid[s][t]==0) q[--front]=st;
                    else q[back++]=st;
                }
            }
        }
        return 0;
    }
};