#define ll long long 
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

         vector<int>ans;

        for(ll i=0; i<spells.size(); i++){
         ll x=success/spells[i];
         x=x+((success%spells[i]==0)?0:1);

         auto it = lower_bound (potions.begin(), potions.end(), x);
         int count=potions.end()-it;
         ans.push_back(count);

        }
        return ans;
    }
};