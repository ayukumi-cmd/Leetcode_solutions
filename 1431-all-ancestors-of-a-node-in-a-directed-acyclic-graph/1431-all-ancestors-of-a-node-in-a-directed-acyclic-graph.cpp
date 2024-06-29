#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ancestors(n);
        vector<int> indegree(n, 0);
        
        // Build the graph
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        // Topological sort using BFS
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                // Add ancestors of the current node to the neighbor
                ancestors[neighbor].insert(ancestors[neighbor].end(), ancestors[node].begin(), ancestors[node].end());
                ancestors[neighbor].push_back(node);
                
                // Remove duplicates and sort
                sort(ancestors[neighbor].begin(), ancestors[neighbor].end());
                ancestors[neighbor].erase(unique(ancestors[neighbor].begin(), ancestors[neighbor].end()), ancestors[neighbor].end());
                
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return ancestors;
    }
};
