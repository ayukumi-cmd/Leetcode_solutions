
class Solution {
public:
    long long ans=0; long long seat=0; vector<long long>vis;
    long long dfs(long long node, vector<long long >adj[]){
        vis[node]=1;

        long long count=1; 
        for(auto it: adj[node]){
            if(!vis[it]){
             
                 count+=dfs(it, adj);        
                
            }
        }
     
        if(node!=0){
           ans += ((count  - 1) / seat)+1; 
        }
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        seat=seats;ans=0;
        vector<long long >adj[roads.size()+1];

        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long n= roads.size();

        vis.resize(n+1, 0);
        int x= dfs(0,adj);
        return ans;


    }
};
