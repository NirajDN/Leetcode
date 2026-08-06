class Solution {
public:
    int smallestNumber(int n, int t) {
        int pro=1;
        int rem=0;
        int temp=n;
        int curr=n;
        while(true){
            pro=1;
            temp=curr;
             while(temp>0){
            rem=temp%10;
            pro=pro*rem;
            temp=temp/10;
        }
         if(pro%t==0){
                return curr;
            }
            else{
                curr++;
            }
        }
        return n;        
    }
};