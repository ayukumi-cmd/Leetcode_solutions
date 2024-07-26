class Solution {
public:
vector<vector<int>>v;
void dfs(vector<int> adj[], vector<int> path, int node, int n){
    path.push_back(node);

    if(node==n){v.push_back(path);}
    for(auto it:adj[node]){
     dfs(adj, path, it, n);
    }
    path.pop_back();
}

 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {


        int n= graph.size();
        vector<int>adj[n+1];

        for(int i=0; i<n; i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
          vector<int>path;
        dfs(adj, path,0,n-1);
        
return v;

    }
};