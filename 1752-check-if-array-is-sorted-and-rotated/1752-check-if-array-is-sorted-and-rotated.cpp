class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int prob=0;
        bool neg=false;
        for(int i=0;i<n;i++){
            int next=(i+1)%n;

            if(nums[i]>nums[next]){
                prob++;
            }
        }
        if(prob==1){
            return neg =!neg;
        }
        if(prob==0){
            return neg=!neg;
        }
        else if(prob>2){
            return neg;
        } 
        return neg;
    }
};