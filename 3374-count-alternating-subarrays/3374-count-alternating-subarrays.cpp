#define ll long long
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll n=nums.size();
        ll cnt=1;ll ans=0;
        for(int i=1; i<n; i++){
         if(nums[i]!=nums[i-1]){
            cnt++;
         }
         else{
            ans+=((cnt+1)*cnt)/2;
            cnt=1;
         }
        }
        ans+=((cnt+1)*cnt)/2;
        return ans;
    }
};
