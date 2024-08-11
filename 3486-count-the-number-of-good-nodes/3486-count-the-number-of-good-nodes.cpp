class Solution {
public:
int count=0;
int solve(vector<vector<int>>&adj,int i,int parent){
    int lastsize=-1;
    bool flag=true;
    int totalsize=1; 
    for(auto it: adj[i]){
        if(it==parent) continue; 
        int s= solve(adj,it,i);
        if(lastsize==-1) lastsize=s;
        else{
            if(lastsize!=s) flag=false; 
        }
        totalsize+=s;
    }
    if(flag) count++; 
    return totalsize; 
}
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n); 
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        count=0;
    
        int x= solve(adj,0,-1);
        return count;
    }
};