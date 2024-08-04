class Solution {
public:
    int mod= 7+1e9;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>range;

        for(int i=0; i<n; i++){
            int sum=nums[i];
            range.push_back(nums[i]);
            for(int j=i+1; j<n; j++){
                sum+=nums[j];
                range.push_back(sum);
            }
        }

        sort(range.begin(), range.end());

        long long  ans=0;

        for(int i=left-1; i<right; i++){
            ans=(ans%mod+range[i]%mod)%mod;
        }

        return ans%mod;
    }
};