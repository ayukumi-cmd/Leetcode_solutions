class Solution {
public:
    int minChanges(vector<int>& nums, int k) 
    {
        vector<int>limit;
        int l=0;
        int r=nums.size()-1;
        unordered_map<int,int>mp;
        while(l<r)
        {
            int mn=min(nums[l],nums[r]);
            int mx=max(nums[l],nums[r]);
            mp[mx-mn]++;
            limit.push_back(max(mx,k-mn));            
            l++;
            r--;
        }
        sort(limit.begin(),limit.end());
        int sz=limit.size();
        int ans=limit.size();
        for(auto it:mp)
        { 
            int curDifference=it.first;
            int DifferenceCount=it.second;
            int extraOperation=lower_bound(limit.begin(),limit.end(),curDifference)-limit.begin();
            extraOperation+=(sz-DifferenceCount);
            ans=min(ans,extraOperation);
        }
        return ans;
    }
};