#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,       tree_order_statistics_node_update> pbds;
class Solution {
public:
    int freq[100001]={0};
    long long int mod=pow(10,9)+7;
    int createSortedArray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        pbds set;
        for(int i=0;i<n;i++)
        {
            set.insert(nums[i]);
            freq[nums[i]]++;
            int count=set.order_of_key(nums[i]);

            ans=(ans+min(count,i+1-count-freq[nums[i]])%mod)%mod;
        }
        return ans;
    }
};