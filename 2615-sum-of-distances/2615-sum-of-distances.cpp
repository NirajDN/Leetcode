class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for(auto &it : mp){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size();

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - pos[i];

                long long left  = 1LL * pos[i] * i - leftSum;
                long long right = rightSum - 1LL * pos[i] * (m-i-1);

                ans[pos[i]] = left + right;

                leftSum += pos[i];
            }
        }

        return ans;
    }
};