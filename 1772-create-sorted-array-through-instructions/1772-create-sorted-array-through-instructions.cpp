#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
     long long int mod=pow(10,9)+7;

    int createSortedArray(vector<int>& nums) {
        ordered_set st;
        int n= nums.size();
         int   ans=0;
        vector<int>mp(100001, 0);
        for(int i=0; i<n; i++){
             
             st.insert(nums[i]);
             mp[nums[i]]++;
             int count=st.order_of_key(nums[i]);
             ans=(ans%mod+min(count,i+1-count-mp[nums[i]])%mod)%mod;
        }
        return  ans%mod;
    }
};

