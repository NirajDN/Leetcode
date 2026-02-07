class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int pr1=2,pr2=1;
        for(int i=3;i<=n;i++){
            int curr=pr1+pr2;
            pr2=pr1;
            pr1=curr;
        }
        return pr1;
        
    }
};                   