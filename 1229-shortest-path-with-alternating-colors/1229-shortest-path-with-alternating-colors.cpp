class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<pair<int,int>> adj[n];
        for (int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],0});
        }
        for (int i=0;i<b.size();i++){
            adj[b[i][0]].push_back({b[i][1],1});
        }
        vector<int> dist(n,1e9);
        dist[0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
         greater<pair<int,pair<int,int>>>> pq;
         pq.push({0,{0,-1}}); //{dist, {node,col}}
         vector<vector<int>> vis(n, vector<int>(2,0));

         while (!pq.empty()){
             int wt=pq.top().first;
             int node=pq.top().second.first;
             int col=pq.top().second.second;
             if (col!=-1)
             vis[node][col]=1;
             pq.pop();

             for (auto it:adj[node]){
                 if (!vis[it.first][it.second] and it.second!=col){
                     if (1+wt<dist[it.first])
                     dist[it.first]=1+wt;
                     pq.push({1+wt, {it.first,it.second}});
                 }
             }
         }
         for (int i=0;i<n;i++){
             if (dist[i]==1e9) dist[i]=-1;
         }
         return dist;
    }
};