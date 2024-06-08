#define ll long long 
class Solution {
public:
    pair<ll,ll>find_idx(vector<int>&nums){
       ll n= nums.size(); ll initial=0; ll end= n-1;
        for(int i=1; i<n; i++){
           if(nums[i]<=nums[i-1]){
            break;
           }
           else{
            initial++;
           }
        }
        for(int i=n-2; i>=0; i--){
           if(nums[i]>=nums[i+1]){
            break;
           }
           else{
            end--;
           }
        }
        return make_pair(initial, end);
    }

    long long incremovableSubarrayCount(vector<int>& nums) {
        ll n= nums.size();ll ans=0;
        auto p=find_idx(nums); ll init=p.first; ll end=p.second;
        cout<<init<<" "<<end<<endl;
        if(end<=init){return (n*(n+1))/2;}
        vector<ll>search_space;
        for(ll i= end; i<n; i++){
            search_space.push_back(nums[i]);
        }
        for(ll i=0; i<=init; i++){
            auto it= upper_bound(search_space.begin(), search_space.end(), nums[i]);
            ans+=search_space.end()-it+1;
            cout<<search_space.end()-it+1<<endl;
        }
        ans+=(search_space.size()+1);
        return ans;
    }
};