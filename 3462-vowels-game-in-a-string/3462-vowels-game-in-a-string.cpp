class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++)
            if ((0x104111 >> (s[i] - 97)) & 1)
                return 1;                                
        return 0;
    }
};