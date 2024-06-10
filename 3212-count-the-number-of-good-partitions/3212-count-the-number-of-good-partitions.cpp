#define ll long long 
class Solution {
public:
    ll mod=1000000007;
       ll merge(vector<vector<ll>> &arr) {
        ll n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<ll>> ans;
        for (ll i = 0; i < n; i++) {
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
       return ans.size();
    }
    ll binexp(ll a , ll b , ll mod){
        ll ans=1;
        a= a%mod;
        while(b){
            if(b&1){
                ans= (ans*a)%mod;
            }
            a=(a*a)%mod;
            b=b>>1;
        }
        return ans%mod;
    }
     int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<ll, pair<ll, ll>> mp;
        ll n = nums.size();
        for (ll i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                auto it = mp.find(nums[i]);
                (it->second).second = i;
            } else {
                mp.insert({nums[i], make_pair(i, i)});
            }
        }
        vector<vector<ll>> v;
        for (auto it : mp) {
            vector<ll> temp = { (it.second).first, (it.second).second };
            v.push_back(temp);
        }
        ll b=merge(v);
        return binexp(2, b-1, mod);
    }
};
