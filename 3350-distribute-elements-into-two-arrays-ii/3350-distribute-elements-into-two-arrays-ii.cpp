#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>v1,v2;
        ordered_set s1,s2;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        s1.insert({nums[0],0});
        s2.insert({nums[1],1});

        for(int i = 2 ; i < nums.size() ; i++){


            int g1 = s1.order_of_key({nums[i]+1,INT_MIN});
            int g2 = s2.order_of_key({nums[i]+1,INT_MIN});
            int sz1 = v1.size()-g1;
            int sz2 = v2.size()-g2;

            if(sz1 > sz2){
                v1.push_back(nums[i]);
                s1.insert({nums[i],i});
            } 
            else if(sz1 < sz2){
                v2.push_back(nums[i]);
                s2.insert({nums[i],i});
            }
            else if(sz1 <= sz2){
             if(v1.size()<=v2.size()){
                v1.push_back(nums[i]);
                s1.insert({nums[i],i});
             }
             else {
                v2.push_back(nums[i]);
                s2.insert({nums[i],i});
             }
            }
         
        }

        for(auto i : v2){
            v1.push_back(i);
        }
        return v1;
    }
};