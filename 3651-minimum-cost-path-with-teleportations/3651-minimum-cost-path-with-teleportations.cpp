const int M=1e4+1, NN=6400;
const int INF=1e9+7;

//x_pos[x] consists in 1D indices of (i, j)  with grid value x
vector<int> x_pos[M]; 

// dp[t][idx] with <= t teleports & idx(i,j)
unsigned dp[11][NN]; 

// Suffix Min
unsigned suffixMin[M]; 

class Solution {
public:
    //1D index 
    static inline int idx(int i, int j, int c) { return i*c+j; }

    static int minCost(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;

        int xMax=0;
        //Group indices by values of grid
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                const int x=grid[i][j];
                x_pos[x].push_back(idx(i, j, c));
                xMax=max(xMax, x);
            }
        }

        //Initialize DP table
        for(int t=0; t<=k; t++)
            fill(dp[t], dp[t]+N, INF);

        //Base Case: 0 Teleports step by step
        dp[0][0]=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j <c; j++) {
                const int pos=idx(i, j, c), x=grid[i][j];
                if (i>0)
                    dp[0][pos]=
                        min(dp[0][pos], dp[0][idx(i-1, j, c)]+x);
                if (j>0)
                    dp[0][pos]=
                        min(dp[0][pos], dp[0][idx(i, j-1, c)]+x);
            }
        }

        // DP with t Teleports
        for (int t=1; t<=k; t++) {
            // Compute suffixMin[x] 
            unsigned currMin=INF;
            for (int x=xMax; x>=0; x--) {
                for (int idx : x_pos[x]) {
                    currMin=min(currMin, dp[t-1][idx]);
                }
                suffixMin[x]=currMin;// teleport
            }

            // Update cells for current teleport 
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    const int pos=idx(i, j, c), x=grid[i][j];

                    // best result with fewer teleports or by teleport
                    dp[t][pos]=min(dp[t-1][pos], suffixMin[x]);

                    // step from up or Left
                    if (i>0)
                        dp[t][pos]=
                            min(dp[t][pos], dp[t][idx(i-1, j, c)]+x);
                    if (j>0)
                        dp[t][pos]=
                            min(dp[t][pos], dp[t][idx(i, j-1, c)]+x);
                }
            }
        }

        int ans=dp[k][N-1];

        // Reset for the next testcase
        for (int x=1; x<=xMax; x++)
            x_pos[x].clear();

        return ans;
    }
};