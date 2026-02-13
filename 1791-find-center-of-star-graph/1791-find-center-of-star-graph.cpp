class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m=edges.size();
        int n=edges[0].size();
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            int currEl=edges[i][j];
            mp[currEl]++;
            }
        }
        for(auto it:mp){
            if(it.second>1){
                return it.first;
            }
        }
        return 1;
    }
};