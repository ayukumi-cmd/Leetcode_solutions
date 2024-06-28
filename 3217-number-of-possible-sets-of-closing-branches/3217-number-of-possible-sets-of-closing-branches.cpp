#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int totalSets = 0;  // Initialize the count of valid sets
        int Total = 1 << n;  // Total possible sets (2^n)
        
        // Iterate through all subsets
        for (int i = 0; i < Total; i++) { 
            vector<int> excluded;  // Store the subset (excluded nodes)
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    excluded.push_back(j);
                }   
            }

            vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));

            // Initialize the adjacency matrix with the given roads
            for (const auto& road : roads) {
                int from = road[0];
                int to = road[1];
                int wt = road[2];
                matrix[from][to] = min(wt, matrix[from][to]);
                matrix[to][from] = min(wt, matrix[to][from]);
            }

            // Set diagonal elements to zero
            for (int j = 0; j < n; j++) {
                matrix[j][j] = 0;
            }

            // Exclude nodes in the current subset by setting their distances to infinity
            for (const auto& node : excluded) {
                for (int k = 0; k < n; k++) {
                    matrix[node][k] = INT_MAX;
                    matrix[k][node] = INT_MAX;
                }
            }

            // Floyd-Warshall algorithm to compute shortest paths
            for (int k = 0; k < n; k++) {
                for (int p = 0; p < n; p++) {
                    for (int q = 0; q < n; q++) {
                        if (matrix[p][k] < INT_MAX && matrix[k][q] < INT_MAX) {
                            matrix[p][q] = min(matrix[p][q], matrix[p][k] + matrix[k][q]);
                        }
                    }
                }
            }

            // Check if the maximum distance in the matrix is less than or equal to maxDistance
            bool validSet = true;
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    if (find(excluded.begin(), excluded.end(), p) == excluded.end() &&
                        find(excluded.begin(), excluded.end(), q) == excluded.end() &&
                        matrix[p][q] > maxDistance) {
                        validSet = false;
                        break;
                    }
                }
                if (!validSet) break;
            }

            if (validSet) {
                totalSets++;
            }
        }
        
        return totalSets;  // Return the count of valid sets
    }
};
