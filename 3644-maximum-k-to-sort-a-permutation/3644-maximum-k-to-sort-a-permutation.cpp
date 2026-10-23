class Solution {
public:
    static int sortPermutation(vector<int>& nums) {
        const unsigned n=nums.size();
        int k0=bit_ceil(n)-1, k=k0;
        for(int i=0; i<n; i++){
            const int x=nums[i];
            k&=(-(x!=i)& x)+(-(x==i));
        }
        return k==k0?0:k;
    }
};