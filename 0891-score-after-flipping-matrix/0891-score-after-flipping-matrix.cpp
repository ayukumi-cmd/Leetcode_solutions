class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
      ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            int a=grid[i][0];
            if(a==0)
            {
                for(int j=0;j<m;j++)
                {
                    grid[i][j]=!grid[i][j];
                }
            }
        }
        int ans=0,k=1;
        for(int i=m-1;i>=0;i--)
        {
            int a=0;
            for(int j=0;j<n;j++)
            {
                cout<<grid[j][i]<<" ";
                if(grid[j][i]==0)
                {
                    a++;
                }
            }
            a=max(a,n-a);
            ans+=a*k;
            k*=2;
        }
        return ans;
    }
};