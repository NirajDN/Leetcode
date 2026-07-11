class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> A(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            A[u].push_back(v);
            A[v].push_back(u);
        }

        bitset<51> vis;
        int res = 0;

        for (int i = 0; i < n; i++) {
            bool state = vis.test(i);

            if (!state) {
                int V = 0, D = 0;

                auto dfs = [&](auto& self, int x) -> void {
                    V++;
                    D += A[x].size();
                    vis.set(x);

                    for (auto& state : A[x])
                        if (!vis.test(state))
                            self(self, state);
                };

                dfs(dfs, i);

                res += D == V * (V - 1);
            }
        }

        return res;
    }
};