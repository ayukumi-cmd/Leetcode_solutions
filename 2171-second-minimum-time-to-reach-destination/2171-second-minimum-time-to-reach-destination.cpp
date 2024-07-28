#define  PII pair<int,int>
class Solution {
public:
   
   
    vector<int> dijkstra(vector<int>graph[], int source, int time, int change, int n) {
        
        vector<int> dis(n+1, INT_MAX);
        vector<int> dis2(n+1, INT_MAX);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        dis[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();

            for (auto nei : graph[node]) {
                int new_cost = cost + time;
             //   cout<<cost<<" ";
                if ((cost / change) % 2 == 1) {
                    new_cost += change - (cost % change);
                }
              //  cout<<new_cost<<endl;

                if (dis[nei] > new_cost) {
                    dis2[nei] = dis[nei];
                    dis[nei] = new_cost;
                    pq.push({new_cost, nei});
                } else if (new_cost > dis[nei] && new_cost < dis2[nei]) {
                    dis2[nei] = new_cost;
                    pq.push({new_cost, nei});
                }
            }
        }

        return {dis[n], dis2[n]};
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
       vector<int>graph[n+1];
      
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> result = dijkstra( graph ,1, time, change, n);
        return result[1];
    }
};
