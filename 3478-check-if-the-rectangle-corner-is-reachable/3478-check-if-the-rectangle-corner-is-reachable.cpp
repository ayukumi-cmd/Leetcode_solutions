class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        vector<vector<int>> graph(n);
        set<int> bottom,right,left,up;
      
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(1ll*(circles[i][2]+circles[j][2])*(circles[i][2]+circles[j][2])>=
                  1ll*(circles[i][0]-circles[j][0])*(circles[i][0]-circles[j][0])+1ll*(circles[i][1]-circles[j][1])*(circles[i][1]-circles[j][1])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
            if(circles[i][1]<=circles[i][2]){
                bottom.insert(i);
            }
            if(circles[i][0]<=circles[i][2]){
                left.insert(i);
            }
            if(Y-circles[i][1]<=circles[i][2]){
                up.insert(i);
            }
            if(X-circles[i][0]<=circles[i][2]){
                right.insert(i);
            }
        }

 // from bottom to up and left obstacles

        bool pos=true;
        queue<int> q;
        vector<int> vis(n,0);
        for(auto& b:bottom){
            q.push(b); vis[b]=1;
        }

        while(!q.empty()){
            int node=q.front();q.pop();
            if(up.contains(node) || left.contains(node)){
                pos=false;
                break;
            }
            for(auto& g:graph[node]){
                if(!vis[g]){
                    vis[g]=1; 
                    q.push(g);
                }
            }
        }
        if(!pos) return false;

// for right to up and left obstacles 

        for(int i=0;i<n;++i) vis[i]=0;
        for(auto& r:right){
            q.push(r);vis[r]=1;
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            if(up.contains(node) || left.contains(node)){
                pos=false;
                break;
            }
            for(auto& g:graph[node]){
                if(!vis[g]){
                    vis[g]=1; q.push(g);
                }
            }
        }
        return pos;
    }
};