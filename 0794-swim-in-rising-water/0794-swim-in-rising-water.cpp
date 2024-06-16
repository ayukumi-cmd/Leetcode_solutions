

class Solution {
public:
   int swimInWater(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n= heights.size();
        int m= heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=heights[0][0];
        pq.push({heights[0][0],{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 and c==m-1){
            return diff;
        }
            for(int i=0; i<4; i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0 and newr<n and newc>=0 and newc<m){
                    int neweffort= max(heights[newr][newc],diff);
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc]=neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};