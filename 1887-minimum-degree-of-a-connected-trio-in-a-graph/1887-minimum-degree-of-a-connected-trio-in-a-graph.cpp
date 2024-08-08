// class Solution {
// public:
//     vector<int>p;
//     set<vector<int>>st;
//     void dfs(int node, int par,vector<int>&vis,vector<int>adj[] ){
//         vis[node]=1;
//         p[node]=par

//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 dfs(it, node, vis, adj);
//             }
//             else if(p[par]==it){
//                 vector<int>temp; 
//                 temp.push_back(node, par, it);
//                 st.insert(temp);
//             }
//         }
//     }
//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         vector<int>adj[n+1];

//         vector<int>degree(n+1, 0);

//         for(int i=0; i<edges.size(); i++){
//             adj[edges[i][0]].push_back(adj[edges[i][1]]);
//             adj[edges[i][1]].push_back(adj[edges[i][0]]);
//             degree[edges[i][0]]++;
//             degree[edges[i][1]]++;
//         }

//         vector<int>vis(n+1, 0);
//         par.resize(n+1, -1);

//         for(int i=1; i<=n; i++){
//             if(!vis[i]){
//                 dfs(i, -1,vis,adj);
//             }
//         }
//        int ans=INT_MAX;
//        for(auto &it:st){
//         int a=it[0],b=it[1],c=it[2];
//         int res=(degree[a]-2)+(degree[b]-2)+(degree[c]-2);
//         ans= min(ans, res);
//        }
//        return res;

//     }
// };




class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1);
        vector<vector<int> > adj(n + 1, vector<int>(n + 1));
        for(auto &e : edges) {
            ++degree[e[0]];
            ++degree[e[1]];
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; ++i) {
      
            for(int j = i + 1; j <= n; ++j) {

                for(int k = j + 1; k <=n; ++k) {
            
                 if(adj[i][j] && adj[j][k] && adj[k][i] and degree[i]>=2 and degree[j]>=2 and degree[k]>=2) {
                        ans = min(ans, degree[i] - 2 + degree[j] - 2 + degree[k] - 2);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};