#define ll long long 
#include <vector>
using namespace std;

class Solution {
public:
    ll binexp(ll a, ll b, ll m) {
        ll ans = 1;
        a = a % m; // Initial modulo
        while (b > 0) {
            if (b % 2 == 1) { // If b is odd
                ans = (ans * a) % m;
            }
            a = (a * a) % m; // Square a and reduce modulo m
            b = b >> 1; // Divide b by 2
        }
        return ans;
    }

    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        int n = v.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ll res1 = binexp(v[i][0], v[i][1], 10); 
            ll res2 = binexp(res1, v[i][2], v[i][3]); 
            if (res2 == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
