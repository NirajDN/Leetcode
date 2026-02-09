class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int boats=0;
        int addOns=0;
        sort(people.begin(),people.end());
        for(int right=n-1;right>=addOns;right--){
            boats++;
            if(people[right]+people[addOns]<=limit){
                addOns++;
            }
        }
        return boats;
        
    }
};