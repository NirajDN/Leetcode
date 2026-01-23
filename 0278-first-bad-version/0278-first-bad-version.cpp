// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int kk;
        for(int i=n;i>0;i--){
            if(isBadVersion(i)){
                kk=i;
            }
            else break;
        }
        return kk;
        
    }
};