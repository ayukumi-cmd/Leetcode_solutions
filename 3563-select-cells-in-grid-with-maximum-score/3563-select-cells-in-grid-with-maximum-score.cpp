class Solution {
public:
    vector<vector<int>>dp;
    int recur(vector<vector<int>>& values, int idx, int mask_row)
    {
        int n= values.size();
        if(idx == n)
            return 0;
        
        if(dp[idx][mask_row]!= -1)
            return dp[idx][mask_row];
        
        int ans = 0;
        int row = values[idx][1];
        int cmask=1<<row;
        if(cmask & mask_row)
            ans += recur(values, idx+1, mask_row);
        else
        {
            int j = idx;
            while (j< n and values[idx][0]== values[j][0])
                j++;
            
            int ans1= values[idx][0]+ recur(values, j, mask_row | (1<<row));
            int ans2 = recur(values, idx+1, mask_row);
            
            ans= max(ans1, ans2);
        }
            
        return dp[idx][mask_row]= ans;
        
    }
    int maxScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> values;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                values.push_back({grid[i][j], i, j});
            }
        }
        
        
        sort(values.begin(), values.end(), greater<vector<int>>());
        dp.resize(101, vector<int>(1<<11, -1));
        
        return recur(values, 0, 0);
    }
};