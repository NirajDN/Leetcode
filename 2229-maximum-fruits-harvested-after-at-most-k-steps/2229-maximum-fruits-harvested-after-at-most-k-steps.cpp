class Solution {
public:
    bool isValid(int left,int right,int startPos,int k) {
        if(right<=startPos) {
            return startPos-left<=k;
        }
        else if(left>=startPos) {
            return right-startPos<=k;
        }
        else {
            int x=startPos-left;
            int y=right-startPos;

            return (2*x + y)<=k || (2*y + x)<=k;
        }

    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int ans=INT_MIN;
        int sum=0;

        int left=0;

        for(int right=0;right<n;right++) {
            sum+=fruits[right][1];
            while(left<=right && !isValid(fruits[left][0],fruits[right][0],startPos,k)) {
                sum-=fruits[left++][1];
            }
            ans=max(ans,sum);
        }

        return ans;
    }
};