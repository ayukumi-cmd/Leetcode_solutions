#include <vector>
using namespace std;

class Solution {
public:
  
    long long minEnd(int n, int x) {
        vector<long long> x_bit(64, 0);
        vector<long long> n_bit(64, 0);

        for (long long i = 0; i < 32; i++) {
            x_bit[i] = (x >> i) & 1;
            n_bit[i] = ((n-1) >> i) & 1;
        }
        long long i = 0, j = 0;
        while (i < 64 ) {
            if (x_bit[i] == 0) {
            x_bit[i] = n_bit[j];
            j++;
            }
             i++;
        }

        long long ans = 0;
        for (long long i = 0; i < 64; i++) {
            ans += (1LL<<i) * x_bit[i];
        }


        return ans;
    }
};