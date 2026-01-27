class Solution {
public:
  const int INF = 1e9 ;
    int minCost(int n, vector<vector<int>>& edges) {
      vector<vector<pair<int,int>>> adj(n) ;
      for (const vector<int> &e : edges) {
        int u = e[0], v = e[1], w = e[2] ;
        adj[u].push_back({v,1LL*w}) ;
        adj[v].push_back({u,1LL*(w << 1)}) ;
      }
      vector<int> d(n,INF) ;
      using T = pair<int,int> ; 
      priority_queue<T, vector<T>,greater<T>> pq ;
      pq.push({0,0}) ;
      d[0] = 0 ;
      while (!pq.empty()) {
        auto [dis,u] = pq.top() ;
        pq.pop() ;
        if (dis != d[u]) continue ;
        if (u == n - 1) return dis ;
        for (auto &[v,w] : adj[u]) {
          if (dis + w < d[v]) {
            d[v] = dis + w ;
            pq.push({d[v],v}) ;
          }
        }
      }
      return -1 ; 
    }
};