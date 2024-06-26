class Solution {
    vector<int> dx={0,0,1,-1};vector<int>dy={-1,1,0,0};
    int n,m;
    int BFS(vector<vector<int>>& forest ,int sx,int sy,int ex, int ey){
        vector<vector<bool>> vis(n,vector<bool>(m,false));int c = 0;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = true;
        
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                
                pair<int,int> p = q.front();q.pop();
                
                if(p.first == ex and p.second == ey) return c;
                for(int i = 0;i<4;i++){
                    int newX=p.first + dx[i];
                    int newY=p.second + dy[i];
                    if(newX<0 || newY<0 || newX==n || newY==m || forest[newX][newY]==0 || vis[newX][newY]==true)continue;
                    vis[newX][newY]=true;
                    q.push({newX,newY});
                }
            }c++;
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int ans = 0;n=forest.size(),m=forest[0].size();
        vector<vector<int>> v;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1) v.push_back({forest[i][j],i,j});
            }
        }
        sort(v.begin(),v.end());
        
        int sx = 0,sy=0;
        for(auto it:v){
            int minStepsForNextTree = BFS(forest,sx,sy,it[1],it[2]);
            if(minStepsForNextTree==-1) return -1;
            ans+=minStepsForNextTree;
            sx = it[1],sy=it[2];
        }
        return ans;
    }
};