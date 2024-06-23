
class Solution {
    long long modii = 300000000;

    long long subarraysDivByK(vector<int>& nums, int m, int k) {
        long long n = nums.size();
        unordered_map<long long, long long> mp;
        long long sum = 0;
        long long res = 0;
        long long x=modii%m;
        modii=modii-x;
        // To count subarrays that directly start from index 0

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            long long modValue = (sum + modii) % m;
            long long target = (modValue - k +m) % m;

            if (mp.find(target) != mp.end()) {
                res += mp[target];
            }
            if(modValue==k){res++;}

            mp[modValue]++;
        }

        return res;
    }

public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }

        return subarraysDivByK(nums, modulo, k);
    }
};
