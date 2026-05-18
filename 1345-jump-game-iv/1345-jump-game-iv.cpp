class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        vector<bool> vis(n,false);
        map<int,vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx == n - 1) return cnt;

                if(idx - 1 >= 0 && !vis[idx - 1]){ q.push(idx-1); vis[idx-1] = true;}
                if(idx + 1 < n && !vis[idx + 1]){ q.push(idx+1); vis[idx+1] = true;}
                
                for(auto x : mp[arr[idx]]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = true;
                    }
                }
                
                mp[arr[idx]].clear();
            }
            cnt++;
        }
        return -1;
    }
};