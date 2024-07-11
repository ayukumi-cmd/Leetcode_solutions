class Solution {
public:
    vector<int>ans;
    
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis, stack<int>st) {
        vis[node] = 1;
        st.push(node);
        
        for (auto adjn : adj[node]) {
            if (!vis[adjn]) {
                if (dfs(adjn, node, adj, vis, st)) {
                    return true;
                }
            } else if (adjn != parent) {
                
               while(st.top()!=adjn){
                ans.push_back(st.top());
                st.pop();
               }
               ans.push_back(st.top());
               st.pop();
                
                return true;
            }
        }
        
        st.pop();
        return false;
    }

    bool iscyle(int v, vector<int> adj[]) {
        vector<int> vis(v + 1, 0);
        stack<int>st;
        
        for (int i = 1; i <= v; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis, st)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> adj[edges.size() +1];
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }



        bool x = iscyle(edges.size(), adj);

        unordered_set<int> st(ans.begin(), ans.end());
        vector<int> res(2, 0);
        
        for (auto it : edges) {
            if (st.find(it[0]) != st.end() && st.find(it[1]) != st.end()) {
                res[0] = it[0];
                res[1] = it[1];
            }
        }
        
        return res;
    }
};
