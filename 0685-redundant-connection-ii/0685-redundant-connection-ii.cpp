class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool union_by_size(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return true;  // Cycle detected

        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // DSU class definition should be provided
        DSU d(edges.size() + 1);
        
        vector<int> indegree(edges.size() + 1, -1);
        int potential_ans1 = -1;
        int potential_ans2 = -1;
        
        // Step 1: Identify any node with two parents
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (indegree[v] == -1) {
                indegree[v] = i;
            } else {
                potential_ans1 = i;
                potential_ans2 = indegree[v];
            }
        }
        
        // Step 2: Use Union-Find to detect cycles
        for (int i = 0; i < edges.size(); i++) {
            if (i == potential_ans1) continue;  // Skip the edge creating the two-parent situation
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            bool flag = d.union_by_size(u, v);
            if (flag) {
                // Cycle detected
                if (potential_ans1 == -1) {
                    // Case 2: Cycle without two parents
                    return edges[i];
                } else {
                    // Case 3: Cycle with two parents
                    return edges[potential_ans2];
                }
            }
        }
        
        // Case 1: Two parents without cycle
        return edges[potential_ans1];
    }
};

// You need to provide a DSU class definition that supports union by size and cycle detection

