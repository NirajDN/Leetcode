class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int total =0;

        for(int i=cost.size()-1;i>=0;i-=3){
            total += cost[i];
            if(i-1>=0) total+=cost[i-1];
        }

        return total;
    }
};