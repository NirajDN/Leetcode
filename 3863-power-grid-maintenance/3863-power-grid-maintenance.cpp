class Solution {
public:
        unordered_map<int, set<int> > mp;
    void dfs(int node,vector<vector<int>> &adj, vector<int> &visited, int id,vector<int> &ids){
        visited[node] = 1;
        ids[node] = id;
        mp[id].insert(node);
        for(auto nodes : adj[node]){
            if(!visited[nodes]){
                dfs(nodes,adj,visited,id,ids);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> visited(c+1,0);

        vector<vector<int>> adj(c+1);

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<int> ids(c+1);


        for(int i=1;i<=c;i++){
            if(!visited[i]){
                dfs(i,adj,visited,i,ids);
            }
        }

        // for(int i=1;i<=c;i++){
        //     cout<<ids[i]<<" ";
        // }
        // cout<<endl;

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0] == 1){


                int node = queries[i][1];

                int check_id = ids[node];
                if(mp[check_id].count(node)){
                    ans.push_back(node);
                }
                else if(mp[check_id].size() != 0){
                    ans.push_back(*(mp[check_id].begin()));
                }
                else ans.push_back(-1);
            }
            else{

                int node=  queries[i][1];

                int check_id = ids[node];

                if(mp[check_id].count(node)){
                    mp[check_id].erase(node);
                }
            }
        }

        return ans;

    }
};