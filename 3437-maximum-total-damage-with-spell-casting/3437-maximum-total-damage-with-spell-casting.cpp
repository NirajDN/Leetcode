class Solution {
public:
    vector<int> uniquePower;
    vector<long long> dp;
    long long fn(int ind, vector<pair<int, long long>>& arr) {
        if (ind >= arr.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        long long nonPick = fn(ind + 1, arr);

        int targetInd = lower_bound(uniquePower.begin(), uniquePower.end(),
                                    uniquePower[ind] + 3) -
                        uniquePower.begin();

        long long pick =
            (0ll + arr[ind].first * arr[ind].second + fn(targetInd, arr));

        return dp[ind] = max(pick, nonPick);
    }
    long long maximumTotalDamage(vector<int>& power) {
        vector<pair<int, long long>> arr;
        map<int, long long> mp;
        for (auto it : power)
            mp[it]++;
        for (auto it : mp) {
            arr.push_back({it.first, it.second});
            uniquePower.push_back(it.first);
        }
        dp.resize(arr.size() + 1, -1);
        return fn(0, arr);
    }
};