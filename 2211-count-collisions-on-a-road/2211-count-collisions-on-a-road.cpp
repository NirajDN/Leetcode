class Solution {
public:
    int countCollisions(string D) {
        int n=D.size();
        if (n==1) return 0;
        int l=0, r=n-1;
        while (D[l]=='L') l++;
        while (D[r]=='R') r--;
    //    cout<<"l="<<l<<" ,r="<<r<<endl;
        if (l>=r) return 0;
        int col=0;
    
        for( ; l<=r; l++){
            while(D[l]=='R'){
                l++;
                col++;
            }
            if (D[l]=='L') col++;
        }
        return col;      
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();