class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

    for(auto&str: strs){
        string key= str;
        sort(key.begin(),key.end());
        mp[key].push_back(str);

    }
    vector<vector<string>> result;
    for(auto&pair : mp){
        result.push_back(pair.second);
    }
    return result;
    }
};