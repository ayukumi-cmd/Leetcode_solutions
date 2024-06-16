#define ll long long
const ll MOD=1000000007;
class Solution {
public:
   ll binexp(ll a, ll b){
    ll ans=1;
    while(b){
        if(b%2==1){
            ans=(ans*a)%MOD;
        }
        a= (a*a)%MOD;
        b=b/2;
    }
    return ans%MOD;
   }
    int sumOfPower(vector<int>& nums) {
        ll n=nums.size(); 
        sort(nums.begin(), nums.end());

        ll sum=0; ll ans=0;
        for(int i=1; i<n; i++){
         sum=(sum%MOD+sum%MOD+nums[i-1]%MOD)%MOD;
         ans+=(binexp(nums[i], 2)*(sum+nums[i]))%MOD;
        }
        ll x=(binexp(nums[0], 2)*nums[0])%MOD;
        ans=(ans%MOD+x)%MOD;
        return ans%MOD;
    }
};