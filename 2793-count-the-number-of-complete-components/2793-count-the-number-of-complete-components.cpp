class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int node, int& cnt) {
        vis[node] = 1;
        cnt++;
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                dfs(adj, vis, it, cnt);
            }
        }
    }

    bool dfs2(vector<int> adj[], vector<int>& vis, int node, int cnt) {
        vis[node] = 1;
        int edgesCount = 0;
        for (auto it : adj[node]) {
            edgesCount++;
        }
        if (edgesCount != cnt - 1) return false; 
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                if (!dfs2(adj, vis, it, cnt)) return false;
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(n, 0);
        vector<int> vis2(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int num = 0;
                dfs(adj, vis, i, num);
                if (dfs2(adj, vis2, i, num)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
