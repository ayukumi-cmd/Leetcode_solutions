class Solution {
public:
    void unionset(int u, int v, vector<int>&parent, vector<int>&rank){
        u=findpar(parent, u);
        v=findpar(parent, v);
        if(u==v){return ;}
        if(rank[u]<rank[v]){parent[u]=v;}
        else if(rank[v]<rank[u]){ parent[v]=u;}
        else {parent[v]=u; rank[u]++;}
        return ;
    }

    int findpar(vector<int>&parent, int node){
        if(parent[node]==node){
            return node;
        }
        parent[node]=findpar(parent, parent[node]);
        return parent[node];
    }

    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<int>parent(26, 0);
        for(int i=0; i<26; i++){parent[i]=i;}
        vector<int>rank(26, 0);
        for(int i=0; i<n; i++){
            int u=(equations[i][0]-'a');
            int v=(equations[i][3]-'a');
            if(equations[i][1]=='='){
              int paru=findpar(parent, u);
              int parv=findpar(parent, v);
              if(paru!=parv){
                unionset(u, v, parent , rank);
              }
            }
        }

        for(int i=0; i<n; i++){
            int u=(equations[i][0]-'a');
            int v=(equations[i][3]-'a');
            if(equations[i][1]=='!'){
              int paru=findpar(parent, u);
              int parv=findpar(parent, v);
              if(paru==parv){return false;}
            }
        }
        return true;
    }
};