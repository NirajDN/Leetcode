class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triplet = num.substr(i, 3);  
                ans = max(ans, triplet);
            }
        }
        return ans;
    }
};