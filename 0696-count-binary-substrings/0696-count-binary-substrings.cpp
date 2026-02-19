int group[100000]={1};
class Solution {
public:
    static int countBinarySubstrings(string& s) {
        const int n=s.size();
        group[0]=1;
        int sz=1;
        for(int i=1; i<n; i++){
            if (s[i]==s[i-1]) group[sz-1]++;
            else group[sz++]=1;
        }
        int cnt=0;
        for(int i=1; i<sz; i++){
            cnt+=min(group[i], group[i-1]);
        }
        return cnt;
    }
};