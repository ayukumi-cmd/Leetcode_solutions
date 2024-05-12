#define ll long long

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        long long cnt=0;
        ll exclude=LLONG_MAX;
        for(int i=0; i<nums.size(); i++){
            if((nums[i]^k)>nums[i]){
                sum+=(ll)(nums[i]^k);
                cnt++;
                exclude= min(exclude, (ll)(nums[i]^k)-(ll)(nums[i]));
            }
            else if((nums[i]^k)<nums[i]){
                sum+=(ll)(nums[i]);
                exclude=min(exclude, (ll)(nums[i])-(ll)(nums[i]^k));
            }
        }
        return (cnt%2==0)?sum:(sum-=exclude);
    }
};