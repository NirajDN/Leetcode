class DSU {
public:
    vector<int> parent, rankv;
    int components;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;

        components--;
        return true;
    }
};

class Solution {
public:
    bool canAchieve(int n, vector<vector<int>>& edges, int k, int x) {
        DSU dsu(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 1) {
                if (s < x) return false;          
                if (!dsu.unite(u, v)) return false; 
            }
        }

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s >= x) {
                dsu.unite(u, v);
            }
        }
        int usedUpgrades = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];

            if (must == 0 && s < x && 2 * s >= x) {
                if (dsu.unite(u, v)) {
                    usedUpgrades++;
                    if (usedUpgrades > k) return false;
                }
            }
        }

        return dsu.components == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        {
            DSU dsu(n);
            for (auto &e : edges) {
                if (e[3] == 1) {
                    if (!dsu.unite(e[0], e[1])) return -1;
                }
            }
        }

        int low = 1, high = 200000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAchieve(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};