class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--){
            int sum=digits[i];
            sum=sum+carry;
            carry=sum/10;
            
            sum=sum%10;
            ans[i]=sum;
            if(carry==1 && i==0){
                ans.insert(ans.begin(),carry);
            }
        }
        return ans;

        
    }
};