
class Solution {
public:
    vector<int> dije(vector<pair<int,int>> g[], int source, int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distTo(n, INT_MAX);
        distTo[source] = 0;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();

            for (auto it = g[prev].begin(); it != g[prev].end(); it++) {
                int next = it->first;
                int nextDist = it->second;
                if (distTo[next] > distTo[prev] + nextDist) {
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        return distTo;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int,int>> adj[n];

        for (auto it : edges) {
            adj[it[0]].push_back(make_pair(it[1], it[2]));
            adj[it[1]].push_back(make_pair(it[0], it[2]));
        }

        int ans_node = -1;
        int min_count = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist = dije(adj, i, n);
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (dist[j] <= threshold) {
                    count++;
                }
            }

            if (count <= min_count) {
                min_count = count;
                ans_node = i;
            }
        }
        return ans_node;
    }
};
