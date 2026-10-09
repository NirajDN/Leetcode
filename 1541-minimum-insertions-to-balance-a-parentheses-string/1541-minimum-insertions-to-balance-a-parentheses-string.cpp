class Solution {
public:
    int minInsertions(string& s) {
        int p=0, n=s.size(), k=0;
        for(int i=0; i<n; i++){
            char c=s[i];
            if (c=='('){
                p+=2;
                if (p&1==1){
                    k++;
                    p--;
                }
            }
            else{
                p--;
                if (p<0){
                    k++;
                    p+=2;
                }
               
            }
        }
        return p+k;
    }
};