class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int count=0;
        int n=letters.size();
        for(char &c:letters){
            if(c>target){
                return c;
            }
            if(target>=c){
                count++;
            }
        }
        if(count==n){
            return letters[0];
        }
        return target;
    }
};