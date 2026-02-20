class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>set;
        for(auto v: nums)if(v!=0)set.insert(v);
        return set.size();
    }
};