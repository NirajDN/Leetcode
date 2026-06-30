class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        unordered_set<int> st;

        for(int x:nums){
            st.insert(x);
        }
        int lnng=0;

        for(int x:st){
            if(st.find(x-1)!=st.end()) continue;

            int curr=x;
            int len=0;
            while(st.find(curr)!=st.end()){
             curr++;
             len++;
            }
            lnng=max(lnng,len);
        }
        return lnng;

    }
};