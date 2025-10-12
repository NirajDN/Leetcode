class Solution {
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> f(M + 1), inverse_f(M + 1);
        f[0] = 1;
        for (int i = 1; i <= M; i++) {
            f[i] = f[i - 1] * i % MOD;
        }

        inverse_f[M] = modPow(f[M], MOD - 2, MOD);
        for (int i = M; i >= 1; i--) {
            inverse_f[i - 1] = inverse_f[i] * i % MOD;
        }

        vector<vector<long long>> pow_nums(n, vector<long long>(M + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int c = 1; c <= M; c++) {
                pow_nums[i][c] = pow_nums[i][c - 1] * nums[i] % MOD;
            }
        }

        vector dp(n + 1, vector(M + 1, vector(K + 1, vector<long long>(M + 1))));
        dp[0][0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int m1 = 0; m1 <= M; m1++) {
                for (int k1 = 0; k1 <= K; k1++) {
                    for (int m2 = 0; m2 <= M; m2++) {
                        long long val = dp[i][m1][k1][m2];
                        if (!val) continue;
                        for (int c = 0; c <= M - m1; c++) {
                            int m12 = m1 + c;
                            int s = c + m2;
                            int bit = s & 1;
                            int k2 = k1 + bit;
                            if (k2 > K) continue;
                            int m22 = s >> 1;
                            dp[i + 1][m12][k2][m22] = (dp[i + 1][m12][k2][m22] + val * inverse_f[c] % MOD * pow_nums[i][c] % MOD) % MOD;
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for (int k1 = 0; k1 <= K; k1++) {
            for (int m2 = 0; m2 <= M; m2++) {
                long long val = dp[n][M][k1][m2];
                if (!val) continue;
                int bits = __builtin_popcount(m2);
                if (k1 + bits == K) {
                    ans = (ans + val) % MOD;
                }
            }
        }

        ans = ans * f[M] % MOD;
        return (int)ans;
    }

private:
    long long modPow(long long a, long long e, int mod) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) res = res * a % mod;
            a = a * a % mod;
            e >>= 1;
        }
        return res;
    }
};