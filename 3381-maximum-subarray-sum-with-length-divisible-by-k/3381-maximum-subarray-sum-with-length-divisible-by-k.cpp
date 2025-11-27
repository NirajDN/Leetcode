
class Solution {
public:
    long long maxSubarraySum(vector<int>& v, int k) {
        map<int, long long> m;
        long long ans = -1e18;
        long long sm = 0;
        for (int i = 0; i < v.size(); i++) {
            sm += v[i];
            int curSZ = i + 1;
            if (curSZ % k == 0)
                ans = max(ans, sm);
            int y = (curSZ % k);
            if (m.find(y) != m.end()) {
                ans = max(ans, sm - m[y]);
                m[y] = min(m[y], sm);
            } else
                m[y] = sm;
        }
        return ans;
    }
};