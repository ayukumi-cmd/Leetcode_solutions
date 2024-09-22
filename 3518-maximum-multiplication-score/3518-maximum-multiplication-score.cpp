#define ll long long 
class Solution {
public: 
    vector<ll>a,b;
    vector<vector<ll>>mp;
    ll solve(ll cnt, ll i){
        if(cnt==4){
            if(i<=b.size()){return 0;}
            else {return -1e12;}
        }
        if(i==b.size()){
           return -1e12;
        }
       
     
        if(mp[cnt][i]!=-1e12){return mp[cnt][i];}

        ll take = a[cnt]*b[i]+ solve(cnt+1, i+1);
        ll nottake= solve(cnt, i+1);
        ll ans= max(take , nottake );
        return mp[cnt][i]=ans;
    }
    long long maxScore(vector<int>& x, vector<int>& y) {
        a.clear();  b.clear(); mp.clear();
        mp.resize(5, vector<ll>(y.size()+1, -1e12));
        for(auto it:x){a.push_back(it);}
        for(auto it:y){b.push_back(it);}
        return solve(0, 0);
    }
};