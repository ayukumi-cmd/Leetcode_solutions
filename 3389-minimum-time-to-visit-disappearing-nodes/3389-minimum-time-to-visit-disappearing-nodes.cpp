class Solution {
public:

    vector<int> dijkstra(vector<pair<int,int>> adj[], int i, int n, vector<int>& disappear) {
        vector<int> dis(n, 1e9);
        dis[i] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        vector<int> vis(n, 0);

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dist > dis[node]) {
                continue;
            }


            for (auto it : adj[node]) {
                int adjnode = it.first;
                int edgeweight = it.second;

                if (dist + edgeweight >= disappear[adjnode]) { 
                    continue; // Skip this edge
                }

                if (dist + edgeweight < dis[adjnode]) {
                    dis[adjnode] = dist + edgeweight;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }
        return dis;
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        for(auto el: edges) {
            int node1 = el[0];
            int node2 = el[1];
            int weight = el[2];
            adj[node1].push_back({node2,weight});
            adj[node2].push_back({node1,weight});
        }

        vector<int> dis = dijkstra(adj, 0, n, disappear);
        vector<int> ans(n);
        for(int i = 1; i < n; i++) {
            if (dis[i] == 1e9) {
                ans[i] = -1;
            } else {
                ans[i] = dis[i];
            }
        }
        return ans;
    }
};
