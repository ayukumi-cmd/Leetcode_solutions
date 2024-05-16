
class Solution {
public:
    vector<int> andi(vector<vector<int>>& edges, vector<int>& comp) {
        vector<int> nd(comp.size(), -1); 
        vector<int> vis_comp(comp.size(), 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            int comp_u = comp[u];

            if (vis_comp[comp_u] == 0) {
                vis_comp[comp_u] = 1;
                nd[comp_u] = cost;
            } else {
                nd[comp_u] &= cost;
            }
        }
        return nd;
    }

    void dfs(vector<vector<int>>& adj, int node, vector<int>& comp, int c, vector<int>& vis) {
        vis[node] = 1;
        comp[node] = c;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(adj, neighbor, comp, c, vis);
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> comp(n, 0);
        vector<int> vis(n, 0);
        int c = 1;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(adj, i, comp, c, vis);
                c++;
            }
        }

        vector<int> andd = andi(edges, comp);
        vector<int> ans;

        for (const auto& q : query) {
            if (comp[q[0]] != comp[q[1]]) {
                ans.push_back(-1);
            } else {
                ans.push_back(andd[comp[q[0]]]);
            }
        }

        return ans;
    }
};
