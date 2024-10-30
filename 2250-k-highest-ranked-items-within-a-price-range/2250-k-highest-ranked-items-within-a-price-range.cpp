

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                            vector<int>& pricing,
                                            vector<int>& start, int k) {
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
        int low = pricing[0], high = pricing[1];

        // Min-heap to store items by (distance, price, row, column)
        priority_queue<tuple<int, int, int, int>, 
                       vector<tuple<int, int, int, int>>, 
                       greater<tuple<int, int, int, int>>> pq;
        // Queue for BFS
        queue<pair<int, int>> q;

        // Start BFS from the start position
        q.push({start[0], start[1]});

        // Direction vectors for moving up, down, left, and right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Visited array to keep track of visited positions
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[start[0]][start[1]] = true;

        int distance = 0;

        // Initial check if the start position is within the pricing range
        int startPrice = grid[start[0]][start[1]];
        if (startPrice >= low && startPrice <= high) {
            pq.push({0, startPrice, start[0], start[1]});
        }

        while (!q.empty()) {
            int q_size = q.size();
            for (int l = 0; l < q_size; l++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; ++i) {
                    int new_row = row + dx[i];
                    int new_col = col + dy[i];
                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                        grid[new_row][new_col] != 0 && !visited[new_row][new_col]) {
                        visited[new_row][new_col] = true;
                        q.push({new_row, new_col});
                        int price = grid[new_row][new_col];
                        if (price >= low && price <= high) {
                            pq.push({distance + 1, price, new_row, new_col});
                        }
                    }
                }
            }
            distance++;
        }

        // Collect the top k items
        while (!pq.empty() && ans.size() < k) {
            auto [dist, price, row, col] = pq.top();
            pq.pop();
            ans.push_back({row, col});
        }

        return ans;
    }
};