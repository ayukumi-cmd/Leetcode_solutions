class Solution {
public:
    
    int tryThis(vector<vector<int>>& grid, int coly, int colo){
        int ans = 0, n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i <= n/2 && (i == j || i+j == n-1))
                || (i > n/2 && j == n/2)){
                    if(grid[i][j] != coly) ans++;
                }else{
                    if(grid[i][j] != colo)ans++;
                }
            }
        }
        
        return ans;
    }
    
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans = min({tryThis(grid, 1, 0), tryThis(grid, 1, 2), 
                      tryThis(grid, 2, 1), tryThis(grid, 2, 0), 
                      tryThis(grid, 0, 1), tryThis(grid, 0, 2)}); 
            
            return ans;
    }
};