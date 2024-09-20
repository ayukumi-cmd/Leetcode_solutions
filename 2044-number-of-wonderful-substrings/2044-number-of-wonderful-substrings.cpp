#define  ll long long 
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;
        mp[0] = 1; int tot_xor = 0;
        ll result = 0;
        for(char ch : word) {

            int shift = ch - 'a';
            tot_xor ^= (1 << shift);

            result += mp[tot_xor];
            for(char ch1 = 'a' ; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';
                ll check_xor = (tot_xor ^ (1 << shift));

                result += mp[check_xor];
            }

            mp[tot_xor]++;

        }

        return result;
    }
};
