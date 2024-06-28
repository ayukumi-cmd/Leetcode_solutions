#define ll long long 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll m=roads.size();
          vector<ll>v(n, 0);
           for(auto it:roads){
            v[it[0]]++; v[it[1]]++;
            }
        sort(v.begin(), v.end(), greater<ll>());
        ll x_factor= n; ll sum=0;
        for(auto it:v){
           sum+= x_factor*(it);
           x_factor--;
        }
        return sum;

    }
};