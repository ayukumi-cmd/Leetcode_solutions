
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> busStops;

        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                busStops[stop].push_back(i);
            }
        }

  
        queue<pair<int, int>> q; 
        unordered_set<int> visitedStops; 
        unordered_set<int> visitedBuses; 

        q.push({0, source});
        visitedStops.insert(source); 

        while (!q.empty()) {
            auto [busCount, curStop] = q.front(); 
            q.pop(); 
            if (curStop == target) return busCount;

            for (int bus : busStops[curStop]) {
                if (visitedBuses.count(bus)) continue; 
                visitedBuses.insert(bus); 

                for (int stop : routes[bus]) {
                    if (!visitedStops.count(stop)) { 
                        visitedStops.insert(stop); 
                        q.push({busCount + 1, stop}); 
                    }
                }
            }
        }
        
        return -1;
    }
};
