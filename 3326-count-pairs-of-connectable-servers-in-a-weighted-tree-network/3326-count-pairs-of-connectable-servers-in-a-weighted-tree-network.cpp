class Solution {
public:
    int possible_path = 0;

    void dfs(vector<pair<int, int>> adj[], int signalSpeed, int path_sum, vector<int>& vis, int node) {
        vis[node] = 1;
        int cnt = 0;
            if( path_sum % signalSpeed ==0){
                possible_path++;
            }
        for (auto j : adj[node]) {
            if (vis[j.first] == 0) {
            dfs(adj, signalSpeed, path_sum + j.second, vis, j.first);  
            }
        }

    }

    int num_elements(vector<vector<int>>& edges) {
        set<int> st;
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
        }
        return st.size();
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size();
        int x = num_elements(edges);
        vector<pair<int, int>> adj[x];
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
            adj[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
        }

        vector<vector<int> >ans; 

        for (int i = 0; i < x; i++) {
            vector<int> vis(n + 1, 0);
            vector<int>row;
            vis[i]=1;
            for (auto& j : adj[i]) {
                possible_path = 0;
                int path_sum = 0;
                
                dfs(adj, signalSpeed, path_sum + j.second, vis, j.first);
                row.push_back(possible_path);
            }
            ans.push_back(row);
        }

        vector<int> fin_ans;
        for (int i = 0; i < ans.size(); i++) {
            int sum = 0;
            for (int j = 0; j < ans[i].size(); j++) {
                for (int k = j + 1; k < ans[i].size(); k++) {
                    sum += ans[i][j] * ans[i][k];
                }
            }
            fin_ans.push_back(sum);
        }

        return fin_ans;
    }
};
