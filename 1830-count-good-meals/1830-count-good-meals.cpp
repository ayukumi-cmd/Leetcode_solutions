
class Solution {
    long long int maxOperations(int k,unordered_map<int,int> &mp) {
        long ans = 0;unordered_map<int,bool> pmp;
        for(auto it : mp){
            int x = it.first;
            int y = k - x;
            if(mp.find(y)!=mp.end()){
                if(!pmp[x] || !pmp[y]){
                    long add = long(mp[x])*long(mp[y]);
                    if(x==y) add = (add-mp[x])/2;
                    ans += add;
                    pmp[x] = true,pmp[y] = true;
                }
            }
        }
        return ans;
    }
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> v;int x = 1;long ans = 0; 
        for(int i = 0;i<=21;i++) v.push_back(x),x<<=1;
        unordered_map<int,int> mp;
        for(auto it :deliciousness) mp[it]++;
        for(auto it:v) {
            ans = ans + maxOperations(it,mp);
        }
        
        return int(ans% 1000000007);
    }
};