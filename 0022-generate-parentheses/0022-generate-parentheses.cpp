class Solution {
public:

void recursiveF(int op,int cl,string s, vector <string> &ans){
    if(cl==0){
        ans.push_back(s);
    }
    if(cl>op){
        recursiveF(op,cl-1,s+')',ans);
    }
    if(op>0){
        recursiveF(op-1,cl,s+'(',ans);
    }
}
    vector<string> generateParenthesis(int n) {
        int op=n,cl=n;
        string s="";
        vector<string> ans;
        recursiveF(op,cl,s,ans);
        return ans;
    }
};