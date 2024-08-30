class Solution {
private:
  using p=pair<int, int>;
    int  dijkstra(int r, int c, vector<vector<int>>& dis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<p, int>, vector<pair<p, int>>, greater<pair<p, int>>> pq;

        pq.push({{0, 0}, 1});

        while(!pq.empty()) {
            int row = pq.top().first.first;
            int col = pq.top().first.second;
            int dist = pq.top().second;
            pq.pop();
            if(row==n-1 and col==n-1){
                return dist;
            }

            for(int dr = -1; dr <= 1; dr++) {
                for(int dc = -1; dc <= 1; dc++) {
                    int nr = row + dr;
                    int nc = col + dc;

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                        if(dist + 1 < dis[nr][nc]) {
                            dis[nr][nc] = dist + 1;
                            pq.push({{nr, nc}, dis[nr][nc]});
                        }
                    }
                }
            }

        }
        return -1;

    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        dis[0][0] = 1;

      return dijkstra(0, 0, dis, grid);


    }
};