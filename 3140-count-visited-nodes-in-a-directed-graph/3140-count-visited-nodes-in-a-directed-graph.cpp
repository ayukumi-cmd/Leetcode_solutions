
class Solution {
public:
   vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        int longest = -1;
        vector<int> recst(n, 0); // Initialize depths to -1
        vector<int>ans;
        // Run DFS for each node to detect cycles and update the longest cycle length
        for (int i = 0; i < n; i++) {
                 vector<int> vis(n, 0); vector<int> depth(n, -1); 
                 longest =-1;
                findCycleLength(adj, i, vis, recst, depth, 0, longest);
                ans.push_back(longest);
       
        }

        return ans;
    }

private:
    void findCycleLength(const vector<vector<int>>& adj, int node, vector<int>& vis, vector<int>& recst, vector<int>& depth, int currentDepth, int& longest) {
        vis[node] = 1;
        recst[node] = 1;
        depth[node] = currentDepth;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                findCycleLength(adj, neighbor, vis, recst, depth, currentDepth + 1, longest);
            } else if (recst[neighbor] == 1) {
                // Cycle detected, calculate cycle length
                longest = max(longest, currentDepth  + 1);
            }
        }

        recst[node] = 0;
    }
};




