class Solution {
public:
    int findUPar(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node], parent); 
    }

    void unionByrank(int u, int v, vector<int>& parent, vector<int>& size, vector<int>&rank) {
        int ulp_u = findUPar(u, parent); 
        int ulp_v = findUPar(v, parent); 
        
        if (ulp_u == ulp_v) return; 
        

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
         parent[ulp_v] = ulp_u;
         size[ulp_u] += size[ulp_v];
        }
    }

    bool isValid(int r, int c, int n) {
        return (r >= 0 && c >= 0 && r < n && c < n); 
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n), size(n * n, 1),rank(n * n, 0);

        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue; 
                int cell = n * i + j; 

                int delR[] = {0, 0, -1, 1};
                int delC[] = {-1, 1, 0, 0};

               
                for (int it = 0; it < 4; it++) {
                    int nrow = i + delR[it];
                    int ncol = j + delC[it];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int adjCell = n * nrow + ncol;
                        unionByrank(cell, adjCell, parent, size, rank); 
                    }
                }
            }
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue; 
                int cell = n * i + j;

                unordered_set<int> uniqueParents;
                int delR[] = {0, 0, -1, 1};
                int delC[] = {-1, 1, 0, 0};

                for (int it = 0; it < 4; it++) {
                    int nrow = i + delR[it];
                    int ncol = j + delC[it];

                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int adjCell = n * nrow + ncol;
                        uniqueParents.insert(findUPar(adjCell, parent)); 
                    }
                }

                int total_size = 0;
                for (auto par : uniqueParents) {
                    total_size += size[par]; 
                }

                maxi = max(maxi, total_size + 1);
            }
        }


        for (int i = 0; i < n * n; i++) {
            maxi = max(maxi, size[findUPar(i, parent)]);
        }

        return maxi;
    }
};
