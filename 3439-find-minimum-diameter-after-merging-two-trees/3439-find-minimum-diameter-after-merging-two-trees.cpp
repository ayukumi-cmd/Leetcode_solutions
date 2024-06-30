class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int node, int& extreme, int& dist, int depth) {
        vis[node] = 1;
        if (depth > dist) {
            dist = depth;
            extreme = node;
        }
        for (auto nbh : adj[node]) {
            if (vis[nbh] == 0) {
                dfs(adj, vis, nbh, extreme, dist, depth + 1);
            }
        }
        return;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> adj1[n];
        vector<int> adj2[m];

        for (auto it : edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto it : edges2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        vector<int> vis1(n, 0);
        int one_extreme1 = 0;
        int dist1 = -1;
        dfs(adj1, vis1, 0, one_extreme1, dist1, 0);
        
        fill(vis1.begin(), vis1.end(), 0);  // Reset the visited array
        int dia1 = -1;
        dfs(adj1, vis1, one_extreme1, one_extreme1, dia1, 0);

        vector<int> vis2(m, 0);
        int one_extreme2 = 0;
        int dist2 = -1;
        dfs(adj2, vis2, 0, one_extreme2, dist2, 0);

        fill(vis2.begin(), vis2.end(), 0);  // Reset the visited array
        int dia2 = -1;
        dfs(adj2, vis2, one_extreme2, one_extreme2, dia2, 0);

        int x = (dia1 + 1) / 2;
        int y = (dia2 + 1) / 2;

        return max({dia1, dia2, x + y + 1});
    }
};
