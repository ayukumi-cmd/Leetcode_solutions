
class Solution {
public:
    void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findpar(parent, u);
        v = findpar(parent, v);
        if (u == v) return;
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int findpar(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        parent[node] = findpar(parent, parent[node]);
        return parent[node];
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int m = s.size();
        vector<int> parent(m);
        vector<int> rank(m, 0);

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        for ( auto& pair : pairs) {
            unionset(pair[0], pair[1], parent, rank);
        }

    
        map<int, vector<int>> components;
        for (int i = 0; i < m; i++) {
            int root = findpar(parent, i);
            components[root].push_back(i);
        }

      
        for (const auto& component : components) {
            const vector<int>& indices = component.second;
            string sorted_chars;
            for (int index : indices) {
                sorted_chars += s[index];
            }
            sort(sorted_chars.begin(), sorted_chars.end());
            for (int i = 0; i < indices.size(); i++) {
                s[indices[i]] = sorted_chars[i];
            }
        }

        return s;
    }
};
