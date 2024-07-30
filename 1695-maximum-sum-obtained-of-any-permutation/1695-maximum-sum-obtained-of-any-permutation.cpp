class Solution {
public:
   int mod=7+1e9;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int m=requests.size();
        int n=nums.size();

        vector<long long >line_sweep(n,0);

        for(int i=0; i<m; i++){
         line_sweep[requests[i][0]]++;

         if(requests[i][1]<n-1){line_sweep[requests[i][1]+1]--;}
        }
         long long  cum=0;
        for(int i=0; i<n; i++){
         cum+=line_sweep[i];
         line_sweep[i]=cum;
        }
        

        sort(nums.begin(), nums.end(), greater<int>());
        sort(line_sweep.begin(), line_sweep.end(), greater<long long >());
       int ans=0;
        for(int i=0; i<line_sweep.size(); i++){
         
          ans=(ans+line_sweep[i]*nums[i])%mod;
        }

        return ans;

    }
};


