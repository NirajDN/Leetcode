class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> born(n + 2, -1);  
        for (int i = 0; i < n; ++i) born[nums[i]] = i;

        long long fact = 1, sizes = 1;  
        for (int k = 2; k <= n; ++k) fact = fact * k % MOD;
        vector<int> stack = {0};  
        for (int v = 1; v <= n + 1; ++v) {
            while (born[stack.back()] > born[v]) {  
                stack.pop_back();
                sizes = sizes * (v - stack.back() - 1) % MOD;  
            }
            stack.push_back(v);
        }
        return (fact * power(sizes, MOD - 2, MOD) - 1 + MOD) % MOD;  
    }

private:
    long long power(long long b, long long e, long long m) {
        long long r = 1;
        for (b %= m; e; e >>= 1, b = b * b % m)
            if (e & 1) r = r * b % m;
        return r;
    }
};