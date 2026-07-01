class Solution {
public:

    double myPow(double x, int n) {
        double k=0;
        double z=1;
        long long N=n;
        if(n<0){
            N=abs(N);
            k=z/pow(x,N);
            
        }
        else{
            k=pow(x,N);
        }
        return k;
    }
};