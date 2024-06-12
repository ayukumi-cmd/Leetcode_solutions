class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        int longest = -1;
        vector<int> vis(n, 0);
        vector<int> recst(n, 0);
        vector<int> depth(n, -1); // Initialize depths to -1

        // Run DFS for each node to detect cycles and update the longest cycle length
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                findCycleLength(adj, i, vis, recst, depth, 0, longest);
            }
        }

        return longest;
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
                longest = max(longest, currentDepth - depth[neighbor] + 1);
            }
        }

        recst[node] = 0;
    }
};







// class Solution {
// public:
//     int answer = -1;
//     void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visit) {
//         visit[node] = true;
//         int neighbor = edges[node];

//         if (neighbor != -1 && !visit[neighbor]) {
//             dist[neighbor] = dist[node] + 1;
//             dfs(neighbor, edges, dist, visit);
//         } else if (neighbor != -1 && dist.count(neighbor)) {
//             answer = max(answer, dist[node] - dist[neighbor] + 1);
//         }
//     }

//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
//         vector<bool> visit(n);

//         for (int i = 0; i < n; i++) {
//             if (!visit[i]) {
//                 unordered_map<int, int> dist;
//                 dist[i] = 1;
//                 dfs(i, edges, dist, visit);
//             }
//         }
//         return answer;
//     }
// };