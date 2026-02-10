constexpr int N=1e5+1;
short freq[N]={0};
class Solution {
public:
    static int longestBalanced(vector<int>& nums) {
        const int n=nums.size();
        int len=0;
        for(int l=0; l<n; l++){
            int cnt[2]={0};
            for(int r=l; r<n; r++){
                const int x=nums[r];
                if (++freq[x]==1) cnt[x&1]++;
                if (cnt[0]==cnt[1])
                    len=max(len, r-l+1);
            }
            for(int i=l; i<n; i++) freq[nums[i]]=0;
        }
        return len;
    }
};