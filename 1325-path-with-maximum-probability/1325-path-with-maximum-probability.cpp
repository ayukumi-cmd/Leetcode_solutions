// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
//         vector<pair<int,double>> adj[n+1];
//         for(int i=0;i<edges.size();i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             double t=succProb[i];
//             adj[u].push_back({v,t});
//             adj[v].push_back({u,t});
//         }
//         vector<double> dist(n+1,0);
//         dist[start_node]=1;
//         priority_queue<pair<double,int>>pq;
//         pq.push({1,start_node});
//         // stack<int> s;
//         // vector<int> vis(n+1,0);
//         // dfs(adj,vis,k,s);
//         while(!pq.empty()){
//             auto it=pq.top();
//             int tt=it.first;
//             int ngh=it.second;
//             pq.pop();
//             for(auto x:adj[ngh]){
//                 int v=x.first;
//                 int t=x.second;
//                 if(t*tt>dist[v]){
//                     dist[v]=tt*t;
//                     pq.push({tt*t,v});
//                 }
                
//             }
//         }
//         if(dist[end_node]==-1*1e9){return 0;}
//         return dist[end_node];     
//     }
// };


#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create adjacency list with pairs of (neighbor, probability)
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double t = succProb[i];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t}); // Since the graph is undirected
        }

        // Distance (or max probability) array
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0; // Start node has a probability of 1 to itself

        // Max-heap priority queue
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [currentProb, node] = pq.top();
            pq.pop();

          

            for (auto& [neighbor, prob] : adj[node]) {
                double newProb = currentProb * prob;
                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return dist[end_node];
    }
};

