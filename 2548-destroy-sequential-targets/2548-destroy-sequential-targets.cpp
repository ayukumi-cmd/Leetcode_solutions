
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
       unordered_map<int, int> mp;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            int x = nums[i] % space;
            mp[x]++;
        }


        int maxFrequency = 0;
        for (const auto& it : mp) {
            if (it.second > maxFrequency) {
                maxFrequency = it.second;
               
            }
        }
        unordered_set<int>st;
        for(auto it:mp){
         if(it.second==maxFrequency){
            st.insert(it.first);
         }
        }

        int ans=0;
        for(int i=0; i<n; i++){
         if(st.find(nums[i]%space)!=st.end()){
            ans=nums[i]; break;
         }
        }


        return ans;
    }
};
