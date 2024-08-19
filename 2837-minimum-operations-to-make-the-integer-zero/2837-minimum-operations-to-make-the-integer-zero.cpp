class Solution {
public:
    // long long  setbit(long long n){
    //     long long  cnt = 0; 
    //     while (n != 0) {
    //         n = n & (n - 1); cnt++;
    //     }
    //     return cnt;
    // }
    int makeTheIntegerZero(int num1, int num2) {
        long long  ans = LLONG_MAX;
        for (long long  i = 61; i >= 0; i--) {
            long long poss = i;
            long long x = static_cast<long long>(num1) - i * num2;

            if (x < 0) {
                continue;
            }
            long long  bit_count = __builtin_popcountll(x);
            if (bit_count <= i && i <= x) {
               ans = min(ans, i);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
