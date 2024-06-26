// class Solution {
// private:
// long long MOD = 1e9 + 7;
// long long powMod(long long a, long long b ){
//    long long ans=1;
//    a=a%MOD;
//    while(b){
//     if(b&1){
//         ans= (ans*a)%MOD;
//     }
//     a= (a*a)%MOD;
//     b=b/2;
//    }
//    return ans%MOD;

// }
    
// public:

//     int stringCount(int n) {
//         long long ans = 0;

//         // Calculating ans = (26^n) % MOD
//         ans = (ans + powMod(26, n)) % MOD;

//         // Calculating ans += ((2 * n + 72) * (24^(n-1))) % MOD
//         ans = (ans + ((2 * n + 72) % MOD) * powMod(24, n - 1) % MOD) % MOD;

//         // Calculating ans -= ((n + 75) * (25^(n-1))) % MOD
//         ans = (ans - ((n + 75) % MOD) * powMod(25, n - 1) % MOD + MOD) % MOD;

//         // Calculating ans -= ((n + 23) * (23^(n-1))) % MOD
//         ans = (ans - ((n + 23) % MOD) * powMod(23, n - 1) % MOD + MOD) % MOD;

//         return static_cast<int>(ans); // Convert ans to int and return
//     }



// };

class Solution {
private:
long long mod = 1e9 + 7;
long long pow(long long a, long long b ){
   long long ans=1;
   a=a%mod;
   while(b){
    if(b&1){
        ans= (ans*a)%mod;
    }
    a= (a*a)%mod;
    b=b/2;
   }
   return ans%mod;

}
    
public:
    int stringCount(int n) {
    long long ans=0;
    ans=(ans%mod+ pow(26, n)%mod)%mod;
    ans=(ans%mod+((2 * n + 72)%mod * pow(24, n - 1)%mod)%mod)%mod;
    ans=(ans%mod-((n + 75) * pow(25, n - 1)%mod)%mod+mod)%mod;
   
    
     ans=(ans%mod-((n + 23) * pow(23, n - 1)%mod)%mod+mod)%mod;
    return ans%mod;
    }
};
