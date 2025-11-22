class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto& num : nums) ans += (num%3 != 0);
        return ans;
    }
};