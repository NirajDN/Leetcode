const int MOD = 1000000007;
const int LIMIT = 1999;
long long fact[LIMIT];
long long inv[LIMIT];

long long power(long long x, int n) {
    long long ans = 1;

    for (; n > 0; n >>= 1) {
        if ((n & 1) == 1)
            ans = ans * x % MOD;

        x = x * x % MOD;
    }

    return ans;
}

bool start = []() {
    fact[0] = 1;

    for (int i = 1; i < LIMIT; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv[LIMIT - 1] = power(fact[LIMIT - 1], MOD - 2);

    for (int i = LIMIT - 1; i > 0; i--)
        inv[i - 1] = inv[i] * i % MOD;

    return false;
}();

class Solution {
public:
    long long comb(int n, int m) {
        return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
    }

    int numberOfSets(int n, int k) { return comb(n + k - 1, k << 1); }
};