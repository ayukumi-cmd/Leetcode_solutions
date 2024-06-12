#define ll long long 
class Solution {

	int spanningTree(int V, vector<pair<int, int>>adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto &i : adj[node]) {
				int adjNode = i.first;
				int edW = i.second;
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}

public:
    void build(vector<vector<int>>&points,vector<pair<int, int>>adj[]){
        ll n=points.size();
        for(ll i=0; i<n; i++){
            ll srcx=points[i][0];
            ll srcy=points[i][1];
            for(ll j=0; j<n; j++){
                if(i!=j){
                 ll destx=points[j][0]; ll desty=points[j][1];
                 ll distx=abs(destx-srcx);ll disty=abs(desty-srcy);
                 adj[i].push_back({j, distx+disty});
                }
            }
        }

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        ll n=points.size(); vector<pair<int, int>>adj[n];
        build(points, adj);
        return spanningTree(n, adj);
    }
};


