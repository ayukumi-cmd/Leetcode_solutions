#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
       ll n= s.length();
       ll count=0;
       ll ans=0;
       for(ll i=n-1 ; i>=0; i--){
       if(s[i]=='1'){ans+=count ; continue;}
       else if(s[i]=='0'){count++;}
       }
       return ans;
    }
};