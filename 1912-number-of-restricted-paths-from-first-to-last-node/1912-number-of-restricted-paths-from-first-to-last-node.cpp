class Solution {
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    vector<int> memo;
    const int MOD = 1e9 + 7;

    void dijkstra(int n) {
        dist.assign(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[n] = 0;
        pq.push({0, n});

        while (!pq.empty()) {
            auto it = pq.top();
            int d=it.first;
            int u=it.second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, weight] : graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return ;
    }

    int dfs(int node, int n) {
        if (node == 1) {
            return 1; 
        }
        if (memo[node] != -1) {
            return memo[node];
        }
        int count = 0;
        for (auto& [next, weight] : graph[node]) {
            if (dist[node] <dist[next]) {
                count = (count + dfs(next, n)) % MOD;
            }
        }
        memo[node] = count; 
        return count;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        graph.resize(n + 1);
        memo.resize(n + 1, -1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        dijkstra(n);
        return dfs(n, n);
    }
};
