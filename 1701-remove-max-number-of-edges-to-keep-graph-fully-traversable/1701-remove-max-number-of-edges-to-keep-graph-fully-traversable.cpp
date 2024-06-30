#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void makeset(vector<int>& parent, vector<int>& rank, int n) {
        for (int i = 0; i < n; ++i) {
            rank[i] = 0;
            parent[i] = i; 
        }
    }

    int findparent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent, parent[node]); 
    }

    void unionset(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findparent(parent, u);
        v = findparent(parent, v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] > b[0]; 
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), cmp);
        int cnt = 0;

        
        vector<int> parentAlice(n + 1), parentBob(n + 1);
        vector<int> rankAlice(n + 1), rankBob(n + 1);
        makeset(parentAlice, rankAlice, n + 1);
        makeset(parentBob, rankBob, n + 1);

        int edgesUsed = 0;

        for (auto& it : edges) {
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if (type == 3) {
                if (findparent(parentAlice, u) != findparent(parentAlice, v)) {
                    unionset(u, v, parentAlice, rankAlice);
                    unionset(u, v, parentBob, rankBob);
                    edgesUsed++;
                }
            }
        }

        for (auto& it : edges) {
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if (type == 1) {
                if (findparent(parentAlice, u) != findparent(parentAlice, v)) {
                    unionset(u, v, parentAlice, rankAlice);
                    edgesUsed++;
                } 
            } else if (type == 2) {
                if (findparent(parentBob, u) != findparent(parentBob, v)) {
                    unionset(u, v, parentBob, rankBob);
                    edgesUsed++;
                } 
            }
        }
        for (int i = 1; i <= n; ++i) {
         if (findparent(parentAlice, i) != findparent(parentAlice, 1) || findparent(parentBob, i) != findparent(parentBob, 1)) {
                return -1;
            }
        }

        return edges.size()-edgesUsed;
    }
};
