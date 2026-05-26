class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        bitset<26> a=0, A=0;
        for(char c: word){
            if (c>='a') a[c-'a']=1;
            else A[c-'A']=1;
        }
        a=a&A;
        return a.count();
    }
};