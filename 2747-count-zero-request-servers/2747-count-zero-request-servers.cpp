class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        vector<pair<int,int>> q;
        for (int i = 0; i < queries.size(); i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        vector<int> cnt(n + 1), ans(q.size());
        int l = 0, r = 0, active = 0;

        for (auto [t, i] : q) {
            while (r < logs.size() && logs[r][1] <= t)
                if (++cnt[logs[r++][0]] == 1) active++;

            while (l < r && logs[l][1] < t - x)
                if (--cnt[logs[l++][0]] == 0) active--;

            ans[i] = n - active;
        }

        return ans;
    }
};