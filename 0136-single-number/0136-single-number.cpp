class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int, int> mp; 
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int ans; 
        for(auto x: mp) 
        {
            if(x.second == 1) 
            {
                ans = x.first; 
                break; 
            }
        }
        return ans; 
    }
};