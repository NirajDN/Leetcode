class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        for(int x=n; x; x/=10){
            rev=10*rev+x%10;
        }
        rev-=n;
        return rev>=0?rev:-rev;
    }
};