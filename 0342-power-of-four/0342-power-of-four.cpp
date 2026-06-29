class Solution {
public:
    bool solve(int n ){
        if(n<=0) return false;
        if(n==1) return true;
        if(n%4!=0) return false;

        return solve(n/4);

    }
    bool isPowerOfFour(int n) {
        return solve(n);
        
    }
};