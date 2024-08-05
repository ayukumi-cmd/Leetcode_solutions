class Solution {
public:
    int ans = INT_MAX;
    set<pair<int, int>> visited_edges;

    void dfs(vector<pair<int, int>> adj[], int node) {
        for (auto it : adj[node]) {
            int neighbor = it.first;
            int weight = it.second;

            // Check if the edge (node, neighbor) or (neighbor, node) has been visited
            if (visited_edges.count({node, neighbor}) == 0 && visited_edges.count({neighbor, node}) == 0) {
                ans = min(ans, weight);
                visited_edges.insert({node, neighbor});
                visited_edges.insert({neighbor, node});
                
                dfs(adj, neighbor);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n + 1];

        // Build the adjacency list
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        dfs(adj, 1);

        return ans;
    }
};
