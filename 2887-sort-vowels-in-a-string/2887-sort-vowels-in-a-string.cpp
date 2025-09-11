class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vow;
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U') { // condition to check for vowel
                vow.push_back(s[i]);
                pos.push_back(i); //storing positions of vowel 
            }
        }
        sort(vow.begin(),vow.end());
        string answer = s;
        for(int i=0;i<pos.size();i++){
            answer[pos[i]] = vow[i];
        }
        return answer;
    }
};