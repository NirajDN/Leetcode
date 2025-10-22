class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int>mp;
        unordered_map<int,int>hash;
        set<int>points;
        for(auto &it:nums){
            hash[it]++;
            mp[it-k]++;
            mp[it+k+1]--;
            points.insert(it);
            points.insert(it-k);
            points.insert(it+k+1);
        }
        int ans=1;
        int sum=0;
        for(auto &it:points){
            sum+=mp[it];
            ans=max(ans,hash[it]+min(sum-hash[it],numOperations));
        }
        return ans;
    }
};