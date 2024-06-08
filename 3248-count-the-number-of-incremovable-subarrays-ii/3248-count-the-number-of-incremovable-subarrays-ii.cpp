#define ll long long 
class Solution {
public:
pair<ll, ll> find_idx(vector<int>& nums) {
    long long n = nums.size();
    long long initial = 0;
    long long end = n - 1;
    
    // Find the end of the longest increasing prefix
    while (initial < n - 1 && nums[initial] < nums[initial + 1]) {
        initial++;
    }
    
    // Find the start of the longest decreasing suffix
    while (end > 0 && nums[end] >nums[end - 1]) {
        end--;
    }
    
    // If initial and end cross, adjust accordingly
    if (initial >= end) {
        initial = n - 1;
        end = 0;
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