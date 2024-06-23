#include <vector>
#include <unordered_map>
#include <algorithm>

#define ll long long
const ll MODII = 300000000;

class Solution {
public:
    int shortestSubarrayDivByK(vector<int>& nums, int m, int k) {
        ll n = nums.size();
        unordered_map<ll, int> mp;
        ll sum = 0;
        int minLength = n + 1; 
        ll x = MODII % m;
        ll modii = MODII - x;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ll modValue = (sum + modii) % m;
            ll target = (modValue - k + m) % m;

            if (mp.find(target) != mp.end()) {
                int subarrayLength = i - mp[target];
                minLength = std::min(minLength, subarrayLength);
            }

            if(modValue == k) {
                minLength = min(minLength, i + 1);
            }
            mp[modValue] = i;
        }

        return (minLength == n ) ? -1 : minLength; 
    }

    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % p == 0) {
            return 0;
        }
        if(sum < p) {
            return -1;
        }
        int rem = sum % p;
        return shortestSubarrayDivByK(nums, p, rem);
    }
};
