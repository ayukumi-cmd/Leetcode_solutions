class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n= word.size(); 
        int mx=0;
        unordered_map<string, int>mp;
        for(int i=0; i<n; i+=k){
        string sub= word.substr(i, k);
        mp[sub]++;
        mx= max(mx,mp[sub]);
        }

return (n/k)-mx;
    }
};
