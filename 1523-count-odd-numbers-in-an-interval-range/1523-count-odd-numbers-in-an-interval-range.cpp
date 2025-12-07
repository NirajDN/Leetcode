class Solution {
public:
    int countOdds(int low, int high) {
        int odd = (high - low)/2;
        if(low % 2 || high % 2)
            odd++;
        return odd;
    }
};