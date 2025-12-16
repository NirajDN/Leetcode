class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<vector<int>>> dp;

    void dfs(vector<int>& present, vector<int>& future, int node) {

        int maxB = dp[node].size();
        vector<int> pwb(maxB, 0); // profit with buying
        vector<int> pwob(maxB, 0); // profit with out buying
        vector<int> next;

        for(int ch: adj[node]) {
            dfs(present, future, ch);

            next = vector<int> (maxB,0);
            for(int budget = 0; budget<maxB; ++budget) {
                for(int childbudget = budget; childbudget >= 0; --childbudget) {
                    next[budget] = max(next[budget], pwb[budget - childbudget] +  dp[ch][childbudget][1]);
                }
            }
            pwb = next;

            next = vector<int> (maxB,0);
            for(int budget = 0; budget<maxB; ++budget) {
                for(int childbudget = budget; childbudget >= 0; --childbudget) {
                    next[budget] = max(next[budget], pwob[budget - childbudget] +  dp[ch][childbudget][0]);
                }
            }
            pwob = next;
        }

        // calculate max profit for node with/without buying
        int p = present[node-1], f = future[node-1], hp = p>>1;
        for(int budget=0; budget<maxB; budget++) {
            dp[node][budget][0] = max(pwob[budget], (budget >= p) ? max(0, f - p + pwb[budget - p]): 0);
            dp[node][budget][1] = max(pwob[budget], (budget >= hp) ? max(0, f - hp + pwb[budget - hp]): 0);
        }
    }
    
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        adj = vector<vector<int>> (n+1, vector<int>());
        for(auto& edge: hierarchy) adj[edge[0]].push_back(edge[1]);

        dp = vector<vector<vector<int>>> (n+1, vector<vector<int>>(budget+1, vector<int>(2,-1)));
        dfs(present, future, 1);
        return dp[1][budget][0];
    }
};