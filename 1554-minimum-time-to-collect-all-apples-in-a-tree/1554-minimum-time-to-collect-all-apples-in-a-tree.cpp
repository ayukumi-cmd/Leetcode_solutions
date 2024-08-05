class Solution {
public:
  
    int solve(int node, int par , vector<int>adj[],  vector<bool>&app){
        
        int ans=0; 

        for(auto it:adj[node]){
            if(it!=par){
                int x=solve(it, node,adj, app);
                if(x>0||app[it]){ans+=2+x;}
            }
        }

        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
     

         vector<int>adj[n];

         for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
         }


         return solve(0, -1,adj, hasApple);
    }
};