
#define  ll long long 
class Solution {
public:
   long long beautifulSubarrays(vector<int>& word) {
        unordered_map<ll, ll> mp;
        mp[0] = 1; int tot_xor = 0;
        ll result = 0;
        for(auto ele: word) {

            tot_xor ^= (ele);
            result += mp[tot_xor];
            mp[tot_xor]++;

        }

        return result;
    }
};
