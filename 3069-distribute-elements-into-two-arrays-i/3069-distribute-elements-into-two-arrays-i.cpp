class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> A[2]={{nums[0]}, {nums[1]}};
        const int n=nums.size();
        for(int i=2; i<n; i++){
            A[A[0].back()<=A[1].back()].push_back(nums[i]);
        }
        A[0].insert(A[0].end(), A[1].begin(), A[1].end());
        return A[0];
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();