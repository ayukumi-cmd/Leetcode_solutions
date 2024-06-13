class Solution {
public:
    void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findpar(parent, u);
        v = findpar(parent, v);
        if (u == v) {
            return;
        }
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
        parent[node] = findpar(parent, parent[node]); // Path compression
        return parent[node];
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Union for equations with '=='
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                unionset(u, v, parent, rank);
            }
        }

        // Check for contradictions in equations with '!='
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                if (findpar(parent, u) == findpar(parent, v)) {
                    return false;
                }
            }
        }

        return true;
    }
};
