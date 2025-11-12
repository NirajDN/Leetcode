class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int c=count(nums.begin(),nums.end(),1);     // if there is at least 1. then it's easy!
        if(c!=0)    return n-c;
        int res=1e7;        // just a dummy value
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=__gcd(g,nums[j]);
                if(g==1){
                    res=min(res,j-i+(n-1)); // number of operations to make this element 1+ number of non ones (i.e. n-1) .
                    break;
                } 
            }
        }
        return res==1e7?-1:res;
    }
};