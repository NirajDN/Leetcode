constexpr int N=2e5+2;
long long cntB[N], bias;

class Solution {
public:
    static long long countMajoritySubarrays(vector<int>& nums, int target) {
        bias=nums.size()+1;
        int balance=bias;
        memset(cntB , 0, (2*bias)*sizeof(long long));;
        cntB[balance]=1;
        long long ans=0, sum=0;
        
        for (int x : nums) {
            bool isT=x==target;
            sum+=(-isT & cntB[balance])-(-!isT & cntB[balance-1]);
            balance+=(isT<<1)-1;
            cntB[balance]++;
            ans+=sum;
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();