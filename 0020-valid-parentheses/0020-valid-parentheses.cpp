class Solution {
public:
    bool isValid(string s) {
        int s1=s.size();
        if(s1%2!=0) return false;
        stack<char> st;

        for(char &c :s){
            if(c=='{' || c=='[' || c=='('){
                st.push(c);
            }
            else {
                if(st.empty()) return false;
                if(st.top()== '{'&& c== '}' ||
                st.top()== '['&& c== ']'||
                st.top()== '('&& c== ')'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};