class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s)
            if(c == '1')
                ones++;

        s = "1" + s + "1";

        int n = s.size();
        int i = 0;

        int ans = ones;

        // Skip first 1's
        while(i < n && s[i] == '1')
            i++;

        // Read first 0-block
        int c10 = 0;
        while(i < n && s[i] == '0'){
            c10++;
            i++;
        }

        while(i < n){

            // Read middle 1-block
            int c11 = 0;
            while(i < n && s[i] == '1'){
                c11++;
                i++;
            }

            if(c11 == 0)
                break;

            // Read right 0-block
            int c20 = 0;
            while(i < n && s[i] == '0'){
                c20++;
                i++;
            }

            if(c20 == 0)
                break;

            ans = max(ans, ones + c10 + c20);

            // Slide the window
            c10 = c20;
        }

        return ans;
    }
};