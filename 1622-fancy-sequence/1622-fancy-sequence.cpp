class Fancy {
private:
    const int mod = 1e9 + 7;
    vector<long long> val;
    long long a, b;
    long long modPow(long long x, long long y, long long mod) {
        long long res = 1;
        x = x % mod;
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % mod;
            }
            y = y / 2;
            x = (x * x) % mod;
        }
        return res;
    }
public:
    Fancy() : a(1), b(0) {
    }
    
    void append(int val) {
        long long x = (val - b + mod) % mod;
        this->val.push_back((x * modPow(a, mod - 2, mod)) % mod);
    }
    
    void addAll(int inc) {
        b = (b + inc) % mod;
    }
    
    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= val.size()) 
            return -1;
        return (a * val[idx] + b) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */