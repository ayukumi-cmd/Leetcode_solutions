
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
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        vector<bool>ans(queries.size(),false);
        sort(queries.begin(),queries.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);
        int j=0;
        for(int i=0;i<queries.size();i++){
            while(j<edgeList.size()&&edgeList[j][2]<queries[i][2]){
                unionset(edgeList[j][0],edgeList[j][1], parent , rank);
                j++;
            }
            if(findpar(parent, queries[i][0])==findpar(parent, queries[i][1])){
                ans[queries[i][3]]=true;
            }
        }
        return ans;

    }
};