class Solution {
public:
    vector<int> dijkstra(vector<pair<int,int>> adj[], int i, int n) {
        vector<int> dis(n, 1e9);
        dis[i] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int edgeweight = it.second;
                int adjnode = it.first;
                if (dist + edgeweight < dis[adjnode]) {
                    dis[adjnode] = dist + edgeweight;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<bool> ans;
        vector<int> stoa = dijkstra(adj, 0, n);
        vector<int> dtoa = dijkstra(adj, n - 1, n);
        for (auto edge : edges) {
            if ((stoa[edge[0]] + dtoa[edge[1]] + edge[2] == stoa[n - 1]) || (stoa[edge[1]] + dtoa[edge[0]] + edge[2] == stoa[n - 1])) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
