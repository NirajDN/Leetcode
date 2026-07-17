class Solution {
    using ll = long long;
public:
    vector<int> gcdValues(vector<int>& A, vector<long long>& queries) {
        int mx = ranges::max(A);
        vector<int> freq(mx + 1, 0);
        vector<ll> GCD(mx + 1, 0);
        
        for (auto& a : A) freq[a]++;
        
        for (int i = mx; i > 0; i--) {
            ll sm = 0, extra = 0;
            for (int j = i; j <= mx; j += i)
                sm += freq[j], extra += GCD[j];
            GCD[i] = sm * (sm - 1) / 2 - extra;
        }
        
        partial_sum(GCD.begin(), GCD.end(), GCD.begin());
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = ranges::upper_bound(GCD, queries[i]) - GCD.begin();
            
        return res;
    }
};