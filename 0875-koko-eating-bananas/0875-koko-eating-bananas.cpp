class Solution {
public:
    bool check(int mid,vector<int>& piles, int h ){
        long long int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(long long)piles[i]/mid;

            if(piles[i]%mid!=0){
                hours+=1;
            }
        }
        if(hours<=h){
            return true;
        }
    return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=0;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};