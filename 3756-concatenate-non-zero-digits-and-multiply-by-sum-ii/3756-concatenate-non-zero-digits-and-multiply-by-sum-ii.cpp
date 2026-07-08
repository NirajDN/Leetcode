class Solution {
private:
    static constexpr int MOD = 1000000007;
    static constexpr int MAX = 100001;
    inline static int pow[MAX];

    inline static int init = []() {
        pow[0] = 1;
        for (int i = 1; i < MAX; i++)
            pow[i] = pow[i - 1] * 10LL % MOD;
        return 0;
    }();

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> A(n + 1, 0);
        vector<int> B(n + 1, 0);
        vector<int> ln(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            A[i + 1] = A[i] + d;
            B[i + 1] = d ? (B[i] * 10LL + d) % MOD : B[i];
            ln[i + 1] = ln[i] + (d > 0);
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1] + 1;

            long long sub = B[l] * 1LL * pow[ln[r] - ln[l]] % MOD;
            long long x = (B[r] - sub + MOD) % MOD;

            res.push_back(x * (A[r] - A[l]) % MOD);
        }

        return res;
    }
};