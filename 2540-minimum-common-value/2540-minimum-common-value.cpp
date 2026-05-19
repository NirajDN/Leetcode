class Solution {
public:
    static int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if (n1>n2){
            swap(nums1, nums2);
            swap(n1, n2);
        }
        int prev=0;
        for(int i=0; i<n1; i++){
            int x=nums1[i];
            int j=lower_bound(nums2.begin()+prev, nums2.end(), x)-nums2.begin();
            if (j==n2) return -1;
            else if (x==nums2[j]) return x;
            else// x<nums2[j]
                prev=j;
        }
        return -1;
    }
};