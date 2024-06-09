// class Solution {
// public:
//     vector<int>v1;
//     vector<int>v2;
//     void solve(vector<int>&rods, vector<int>&v, int idx, int sum){
//         int n=rods.size();
//         if(idx==n){
//           v.push_back(sum);
//           return ;
//         }
//         solve(rods, v, idx+1, sum);
//         solve(rods, v, idx+1, sum+rods[idx]);
//         return ;

//     }
//     int tallestBillboard(vector<int>& rods) {
//         int n=rods.size();
//         vector<int>half1, half2;
//         for(int i=0; i<n/2; i++){
//             half1.push_back(rods[i]);
//         }
//         for(int i=n/2; i<n; i++){
//             half2.push_back(rods[i]);
//         }
//         solve(half1,v1,0,0);  solve(half2, v2, 0, 0);
//         sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
//         int ans=INT_MIN;
//         unordered_map<int,int>mp;
//         for(auto i:v1){mp[i]++;} for(auto i:v2){mp[i]++;}
//         for(auto i1:v1){
//            for(auto i2:v2){
//            if(i1==i2){ans=max(ans, i1);}
//            if(mp.find(i1+i2)!=mp.end()){ans=max(ans, i1+i2);}
//            }
//         }
//         return ans;
//     }
// };


class Solution {
public:
	int f(int i,int diff,vector<int>& rods,int n,vector<vector<int>>& dp){
		if(i==n){
			if(!diff) return 0;
			return -1e9;
		}
		if(dp[i][5000+diff]!=-1) return dp[i][5000+diff];
		int op1=rods[i]+f(i+1,diff+rods[i],rods,n,dp);
		int op2=rods[i]+f(i+1,diff-rods[i],rods,n,dp);
		int op3=f(i+1,diff,rods,n,dp);
		return dp[i][5000+diff]=max(max(op1,op2),op3);
	}

	int tallestBillboard(vector<int>& rods) {
		int n=rods.size();
		vector<vector<int>> dp(n,vector<int>(10000,-1));
		return f(0,0,rods,n,dp)/2;
	}
};