class Solution {
public:

    vector<int> seg;
    const int MAXX = 50000;

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        seg.resize(4 * (MAXX + 1), 0);

        set<int> obstacles;
        obstacles.insert(0);

        // Build final obstacle configuration
        for (auto &q : queries) {
            if (q[0] == 1) obstacles.insert(q[1]);
        }

        vector<int> pos(obstacles.begin(), obstacles.end());
        // at pos[i] we have a gap of (pos[i] - pos[i - 1]) which we are storing
        // in the segment tree
        for (int i = 1; i < (int)pos.size(); i++) {
            update(1,0,MAXX,pos[i],pos[i] - pos[i - 1]);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 2) {

                int x = queries[i][1];
                int sz = queries[i][2];
                // find a prev obstacle lesser than x, then we can fit the block
                //before prev or between prev to x
                auto it = prev(obstacles.upper_bound(x));

                int prevObstacle = *it;
                int best = query(1,0,MAXX,0,prevObstacle);

                best = max(best, x - prevObstacle);
                ans.push_back(best >= sz);
            }
            else {

                int x = queries[i][1]; // so we now remove x obstacle
                auto it = obstacles.find(x);
                int leftPos = *prev(it); //left of x

                update(1,0,MAXX,x,0); // update gap at x to 0 or remove gap ending at x

                auto rightIt = next(it);

                if (rightIt != obstacles.end()) {
                    int rightPos = *rightIt;
                    // merging the interval from leftpos to rightpos as one single gap
                    update(1,0,MAXX,rightPos,rightPos - leftPos);
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};