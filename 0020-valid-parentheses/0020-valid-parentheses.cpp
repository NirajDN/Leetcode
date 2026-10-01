class Solution {
public:
    bool isValid(string& str) {
        if (str.size() % 2)
            return 0;

        int j = 0;

        for (char s : str)
            if ((s & 3) != 1)
                str[j++] = s;
            else if (j == 0 || ((s - str[--j] + 1) >> 1) != 1)
                return 0;

        return j == 0;
    }
};