class Solution {
public:
    int binaryGap(unsigned n) {
        int d=0, p=32;
        for(; n>0; n&=(n-1)){
            int ctz=countr_zero(n);
            d=max(d, ctz-p);
            p=ctz;
        }
        return d;
    }
};