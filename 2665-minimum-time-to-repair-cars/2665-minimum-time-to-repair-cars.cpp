class Solution {
public:
    using ll = long long;
    ll solve(ll m, vector<int>&ranks, ll cars){
     ll total=0;
     for(int i=0; i<ranks.size(); i++){
        ll x= pow(m/ranks[i], 0.5);
        total+=x;
     }

     return total>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll n= ranks.size();
        ll l= 1; ll h=pow(cars, 2)*(*min_element(ranks.begin(), ranks.end()));
        ll ans=0;
        while(l<=h){
            ll m=l+(h-l)/2 ;
            if(solve(m ,ranks ,cars)){
                ans= m; 
                h= m-1;
            }
            else {
                l=m+1;
            }
        }
        return ans;
    }
};