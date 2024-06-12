class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Create adjacency list with pairs of (neighbor, probability)
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double t = succProb[i];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t}); // Since the graph is undirected
        }

        // Distance (or max probability) array
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0; // Start node has a probability of 1 to itself

        // Max-heap priority queue
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [currentProb, node] = pq.top();
            pq.pop();

           // Early exit if end_node is reached

            for (auto& [neighbor, prob] : adj[node]) {
                double newProb = currentProb * prob;
                if (newProb > dist[neighbor]) {
                    dist[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return dist[end_node];
    }
};

