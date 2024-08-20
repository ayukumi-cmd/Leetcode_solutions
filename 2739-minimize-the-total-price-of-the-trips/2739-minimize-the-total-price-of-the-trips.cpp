class Solution {
private:
    vector<int> contri;vector<int> pr;
    int end;
    void makeContri(int node,vector<int>& curr,vector<int> adj[],int p){
        curr.push_back(node);      
        if(end==node){             
            for(auto& i:curr){
               contri[i]++;   
            }  
            curr.pop_back();
            return;
        }
        for(auto& it:adj[node]){
         if(it!=p) makeContri(it,curr,adj,node);
        }
        curr.pop_back();      
    }
    int dp[51][2];     
    int dfs(int node,vector<int>adj[],int p,bool parentHalved){
        int res1=(contri[node]*pr[node])/2,res2=contri[node]*pr[node];
        
        if(dp[node][parentHalved]!=-1)   return dp[node][parentHalved];
        
        for(auto& ch:adj[node])   if(ch!=p)   res2+=dfs(ch,adj,node,0);
        if(parentHalved) return dp[node][parentHalved]=res2;      
        
        for(auto& ch:adj[node])   if(ch!=p)    res1+=dfs(ch,adj,node,1);
        return dp[node][parentHalved]=min(res1,res2);
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> g[n];
        memset(dp,-1,sizeof dp);
        pr=price;
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        contri.resize(n+1, 0);     
        for(auto& t:trips){
            vector<int> curr; end=t[1];
            makeContri(t[0],curr,g,-1);
        }
        
        return dfs(0,g,-1,0);
        
    }
};