class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxVowel = 0, maxConso = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};