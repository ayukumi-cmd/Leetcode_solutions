class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<long long >row;
        vector<long long>col;
        for(int i=0;i<grid.size(); i++){
            long long cnt=0;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){cnt++;}
            }
            row.push_back(cnt);
        }
        for(int i=0;i<grid[0].size(); i++){
           long long cnt=0;
            for(int j=0; j<grid.size(); j++){
                if(grid[j][i]==1){cnt++;}
            }
            col.push_back(cnt);
        }
        long long ans=0;
        for(int i=0; i<row.size(); i++){
            for(int j=0; j<col.size(); j++){
                if(row[i]>0 and col[j]>0 and grid[i][j]==1){
                 ans+=(row[i]-1)*(col[j]-1);
                }
            }
        }
        return ans;
    }
};