class Solution {
public:
    typedef long long ll;
    static const int MOD = 1e9 + 7;
    struct Node {
        ll sum = 0;
        ll sqsum = 0;
        ll lazy = 0;
    };
    vector<Node> seg;
    void apply(int i, int l, int r, ll val) {
        ll len = r - l + 1;
        seg[i].sqsum += 2LL * val * seg[i].sum + len * val * val;
        seg[i].sum += len * val;
        seg[i].lazy += val;
    }
    void updateRange(int start, int end,int i, int l, int r, ll val) {
        if (seg[i].lazy != 0) {
            if (l != r) {
                apply(2 * i + 1, l, (l + r) / 2, seg[i].lazy);
                apply(2 * i + 2, (l + r) / 2 + 1, r, seg[i].lazy);
            }
            seg[i].lazy = 0;
        }

        if (l > end || r < start || l > r) return;
        if (l >= start && r <= end) {
            apply(i, l, r, val);
            return;
        }
        int mid = (l + r) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);
        seg[i].sum = seg[2 * i + 1].sum + seg[2 * i + 2].sum;
        seg[i].sqsum = seg[2 * i + 1].sqsum + seg[2 * i + 2].sqsum;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n);
        unordered_map<int, int> last;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.count(nums[i])) prev = last[nums[i]];
            updateRange(prev + 1, i, 0, 0, n - 1, 1);
            ans = (ans + seg[0].sqsum) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};