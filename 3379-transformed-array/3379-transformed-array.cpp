class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i ++){
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return result;
    }
};