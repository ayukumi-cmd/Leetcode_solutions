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
    void makeset(vector<int>&parent , vector<int>&rank, int n){

     for(int i=1;i<= n; i++){
        parent[i]=i;
        rank[i]=0;
     }


    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
      vector<int>parent(edges.size()+1);
      vector<int>rank(edges.size()+1);
      makeset(parent, rank, edges.size());
  
       vector<int>ans;
      for(auto it:edges){
        int u= findpar(parent, it[0]);
        int v= findpar(parent, it[1]);

        if(u!=v){
            unionset(u, v, parent, rank);
        }
        else if(u==v){
         ans.push_back(it[0]);
         ans.push_back(it[1]);
        }
      }
      return ans;

    }
};