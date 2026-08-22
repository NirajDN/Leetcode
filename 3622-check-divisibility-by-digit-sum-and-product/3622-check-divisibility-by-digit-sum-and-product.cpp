class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0, p=1;
        for(int x=n; x>0; x/=10){
            const int r=x%10;
            s+=r;
            p*=r;
        }
        return n%(s+p)==0;
    }
};