class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n=nums.size();
        int cnt=0;
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int l=0, r=0; r<n; r++){
            int x=nums[r];
            auto it=freq.find(x);
            int& f=(it==freq.end())?freq[x]=1:++(it->second);
            while (f>k)
                freq[nums[l++]]--;
        
            cnt=max(cnt,r-l+1);
        }
        return cnt;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();