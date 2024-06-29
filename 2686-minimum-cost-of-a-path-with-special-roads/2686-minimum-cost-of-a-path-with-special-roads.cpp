class Solution {
public:
    int manhattanDist(pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        pair<int, int> startPt = {start[0], start[1]};
        pair<int, int> targetPt = {target[0], target[1]};

        vector<pair<int, int>> points = {startPt, targetPt};
        for (auto& road : specialRoads) {
            points.push_back({road[0], road[1]});
            points.push_back({road[2], road[3]});
        }

        unordered_map<int, vector<pair<int, int>>> graph;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = manhattanDist(points[i], points[j]);
                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }

        
        for (auto& road : specialRoads) {
            int u = find(points.begin(), points.end(), make_pair(road[0], road[1])) - points.begin();
            int v = find(points.begin(), points.end(), make_pair(road[2], road[3])) - points.begin();
            int dist=INT_MAX;
            for(auto it:graph[u]){
                if(it.first==v){
               dist= min({dist,it.second});
               break;
                }
            }
            dist= min(dist, road[4]);
            graph[u].push_back({v, dist});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        int startIdx = 0;
        int targetIdx = 1;
        dist[startIdx] = 0;
        pq.push({0, startIdx});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[targetIdx];
    }
};