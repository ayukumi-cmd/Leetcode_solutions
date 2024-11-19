class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long i,ans=0,sum=0,dist=0,j=0;
        map<int,int> cnt;
        for(i=0;i<k;i++)
        {
            sum=sum+nums[i];
            if(cnt[nums[i]]==0) dist++;
            cnt[nums[i]]++;
        }
        if(dist==k) ans=sum;
        for(i=k;i<nums.size();i++)
        {
            sum-=nums[j];
            cnt[nums[j]]--;
            if(cnt[nums[j]]==0) dist--;
            j++;
            sum+=nums[i];
            if(cnt[nums[i]]==0) dist++;
            cnt[nums[i]]++;
            if(dist==k) ans=max(ans,sum);
        }
        return ans;
    }
};