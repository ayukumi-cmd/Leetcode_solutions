#define ll long long 
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ll n = nums.size();
        ll flip = 0;  
        queue<ll> q; 

        for (int i = 0; i < n; ++i) {
   
            if (!q.empty() && q.front() < i) {
                q.pop();
            }

            if (q.size() % 2 == nums[i]) {
            
                ++flip;
         
                q.push(n - 1);
            }
        }
        return flip;
    }
};
