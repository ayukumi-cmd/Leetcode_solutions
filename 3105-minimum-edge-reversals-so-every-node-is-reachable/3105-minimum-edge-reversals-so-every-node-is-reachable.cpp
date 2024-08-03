// class Solution {
// public:
//     int count = 0;
//     vector<int>res;
//     void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
//         visited[node] = true;
        
//         for (auto& [child, sign] : adj[node]) {
//             if (!visited[child]) {
//                count+=!sign;
//                 dfs(child, node, adj, visited);
                
//             }
//         }
       
//     }
//     void dfs2(vector<vector<pair<int, int>>>& adj,int node,vector<bool>& visited ){
//         visited[node]=1;
//          int ans=0;
//         for(auto &[child, sign]:adj[node]){
//             if(!visited[child]){
               
//                 if(sign==1){ans=count+1;}
//                 else if(sign==0){ans= count-1;}
//                 res[child]=ans;
//                 dfs2(adj, child, visited);

//             }
//         }
        
//     }

//   vector<int> minEdgeReversals(int n, vector<vector<int>>& connections) {
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& connection : connections) {
//             adj[connection[0]].push_back({connection[1], 1});
//             adj[connection[1]].push_back({connection[0], 0});
//         }
//         res.resize(n, 0);
//         vector<bool> visited(n, false);
//         dfs(0, -1, adj, visited);
//         res[0]=count;
//         vector<bool> visited2(n, false);
//         dfs2(adj, 0,visited2);
        
//         return res;
//     }
// };


class Solution {
public:
    int count = 0;
    vector<int> res;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (auto& [child, sign] : adj[node]) {
            if (!visited[child]) {
                count += !sign;
                dfs(child, node, adj, visited);
            }
        }
    }

    void dfs2(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[node] = true;
        int ans = res[node];

        for (auto& [child, sign] : adj[node]) {
            if (!visited[child]) {
                if (sign == 1) {
                    res[child] = ans + 1;
                } else {
                    res[child] = ans - 1;
                }
                dfs2(child, adj, visited);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }

        res.resize(n, 0);
        vector<bool> visited(n, false);
        dfs(0, -1, adj, visited);
        res[0] = count;

        fill(visited.begin(), visited.end(), false);
        dfs2(0, adj, visited);
        
        return res;
    }
};
