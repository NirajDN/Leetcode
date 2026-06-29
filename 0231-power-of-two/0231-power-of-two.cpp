class Solution {
public:
    bool get(int n){
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n % 2 != 0) return false;

        return get(n / 2);
    }

    bool isPowerOfTwo(int n) {
        return get(n);
    }
};