class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long total=0;
        for(int x: beans) total+=x;

        long long ans=LLONG_MAX;
        int n=beans.size();

        for(int i=0;i<n;i++){
            long long kp=1LL*beans[i]*(n-i);
            long long rm=total-kp;
            ans=min(ans,rm);
        }
        return ans;
    }
};