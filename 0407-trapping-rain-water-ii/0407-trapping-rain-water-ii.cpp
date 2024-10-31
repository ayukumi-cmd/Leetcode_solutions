class Solution {
private:
  
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
  
        int m = heightMap.size();
        int n = heightMap[0].size();

       
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

    
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int water = 0;  
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int height = p.first;
            int row = p.second.first; 
            int col = p.second.second; 

        
            for (auto& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

            
                if (isSafe(nextRow, nextCol, m, n) && visited[nextRow][nextCol] == false) {
               
                    water += max(0, height - heightMap[nextRow][nextCol]);

                    pq.push({max(height, heightMap[nextRow][nextCol]), {nextRow, nextCol}});

      
                    visited[nextRow][nextCol] = true;
                }
            }
        }

        return water;
    }
};