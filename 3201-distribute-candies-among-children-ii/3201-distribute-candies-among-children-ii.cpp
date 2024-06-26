
class Solution {


public:


long long nCr(int n, int r) {
    if (n < r) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r; 
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

 long long distributeCandies(int n, int limit)  {
    long long totalWays = nCr(n + 2, 2);
    limit= min(limit, n);
    // Subtract invalid cases where at least one child gets more than 'limit' candies
    totalWays -= 3 * nCr(n - (limit + 1) + 2, 2);
     totalWays -= nCr(n - 3 * (limit + 1) + 2, 2);
    totalWays += 3 * nCr(n - 2 * (limit + 1) + 2, 2);
   

    return totalWays;
}


};
