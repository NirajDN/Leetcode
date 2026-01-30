class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        int maxFreq=0;
        for(auto it: freq){
            maxFreq=max(maxFreq,it.second);
        }
        if (maxFreq == 1) return {};

        vector<int>ans;
        for(auto it:freq){
            if(it.second==maxFreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};