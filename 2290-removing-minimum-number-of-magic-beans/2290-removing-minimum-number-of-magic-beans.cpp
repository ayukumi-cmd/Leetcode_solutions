class Solution {
public:
    #define ll long long
    long long minimumRemoval(vector<int>& a) {
        ll sum=0; 
        ll pre_sum=0; 

        ll n = a.size();
        sort(a.begin(), a.end());
        sum = accumulate(a.begin(), a.end(), 0ll);
        ll ans= LLONG_MAX;
        for(ll i=0; i<n; i++){
             sum= sum-a[i];
             ll r= a[i]*(n-i-1);
             ans= min(ans, sum+pre_sum-r);
             pre_sum+=a[i];
        }

        return ans;
    }
};