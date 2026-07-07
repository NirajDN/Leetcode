class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=n;
        long long ans=0;
        long long sum=0;
        long long ans1=0;
        while(x>0){
            long long rem=x%10;
            if(rem!=0){
            ans=ans*10+rem;
            }
            x=x/10;
        }
        while(ans>0){
            long long rem=ans%10;
            sum+=rem;
            ans1=ans1*10+rem;
            ans=ans/10;
        }
    return ans1*sum;
    // return ans;
        
    }
};