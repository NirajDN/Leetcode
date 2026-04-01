class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {

        int n = pos.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int a,int b){ return pos[a] < pos[b]; });

        vector<bool> alive(n,true);
        vector<int> st;

        for(int idx:order){

            if(d[idx]=='R') st.push_back(idx);

            else{
                while(!st.empty()){

                    int top = st.back();

                    if(h[top] < h[idx]){
                        alive[top]=false;
                        st.pop_back();
                        h[idx]--;
                    }
                    else if(h[top] > h[idx]){
                        alive[idx]=false;
                        h[top]--;
                        break;
                    }
                    else{
                        alive[top]=false;
                        alive[idx]=false;
                        st.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++)
            if(alive[i]) res.push_back(h[i]);

        return res;
    }
};