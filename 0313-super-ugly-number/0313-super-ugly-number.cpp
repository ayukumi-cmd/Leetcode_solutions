class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long > ugly(n);
        ugly[0] = 1;
        long long  i2 = 0, i3 = 0, i5 = 0;
        vector<long long >point(primes.size(), 0);
        for (int i = 1; i < n; i++) {
            long long  next_ugly=LLONG_MAX;
            for(long long  j=0; j<primes.size(); j++){
            next_ugly = min(next_ugly, ugly[point[j]] * primes[j]);
            }
            
            ugly[i] = next_ugly;

            for(long long  j=0; j<primes.size(); j++){
                if(next_ugly==primes[j]*ugly[point[j]]){point[j]++;}
            }
        }

        return static_cast<int>(ugly[n - 1]);
    }
};
