class Solution {
public:
    /* concept: we should convert all the no.s to the median of all numbers in sorted order
    bcos it will give the least no. of operations
    */
    bool isPossible(vector<vector<int>> &grid,int x){
        
        int mod = grid[0][0] % x;
        
        for(int i=0;i<grid.size();i++){
            
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j] % x != mod)
                    return false;
            }
        }
        
        return true;
    }
    
    int minOperations(vector<vector<int>>& grid, int x) {
        //if remainder of all numbers are not same, then it is not possible 
        if(isPossible(grid,x)==false)
            return -1;
        
        int row=grid.size();
        int col=grid[0].size();
        
        //make a vector to store all the elements of grid
        vector<int> arr;
        
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                
                arr.push_back(grid[i][j]);
            }
        }
        
        //sort the array now
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        int ans=0; 
        
        //if array is odd, single median is present
        if(n%2 == 1){
            
            int median=arr[n/2];
            for(int i=0;i<n;i++){ //iterate through array
                
                ans += abs(arr[i]-median)/x; //cal no. of operations
              
            }
        }
        
        //else,array is even, two medians
        else{
            int median1=arr[n/2];
            int median2=arr[n/2 - 1];
            
            int ans1=0,ans2=0;
            
            for(int i=0;i<n;i++){
                ans1 += abs(arr[i]-median1)/x;
            }
            
            for(int i=0;i<n;i++){
                ans2 += abs(arr[i]-median2)/x;
            }
            
            //take best of two i.e minimum of two
            ans = min(ans1,ans2);
        }
        
        return ans;
    }
};