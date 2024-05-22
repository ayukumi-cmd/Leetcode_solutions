class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        bool f= true;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(i+1>=n and j+1>=m){
                continue;
            }
            else if(i+1<n and j+1>=m){
                if(grid[i][j] == grid[i+1][j ] ){continue;}
                else {f= false; break;}
            }
            else if(i+1>=n and j+1<m){
                if(grid[i][j] != grid[i][j + 1] ){continue;}
                else {f= false; break;}
            }
            else if(i+1<n and j+1<m){
                 if(grid[i][j] != grid[i][j + 1] and grid[i][j] == grid[i+1][j ]){continue;}
                 else {f=false ; break;}
            }
            }
        }
        return f;
    }
};