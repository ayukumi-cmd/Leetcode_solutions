class Solution {
public:
#define ll long long 
vector<vector<ll>>ar;
vector<vector<ll>>res;

    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n= nums.size();
    ar.resize(n+1, vector<ll>(n+1, 0));
    res.resize(n+1, vector<ll>(n+1, 0));
	for(int i=0; i<n; i++){
        ar[0][i]=nums[i];
        res[0][i] = ar[0][i];
    }
	
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			ar[i][j] = ar[i-1][j] ^ ar[i-1][j+1];
			res[i][j] = max(ar[i][j] , max(res[i-1][j] , res[i-1][j+1]));
		}
	}
    vector<int>ans; 

    for(int i=0; i<queries.size(); i++){
       int row= queries[i][1]-queries[i][0];
       int col=queries[i][0];
       ans.push_back(res[row][col]);
    }
    return ans;
    }
};




