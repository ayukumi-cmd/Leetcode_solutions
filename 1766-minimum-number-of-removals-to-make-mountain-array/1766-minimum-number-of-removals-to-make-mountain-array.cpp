#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int lis1[n];
        for (int i = 0; i < n; i++) {
            lis1[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis1[i] = max(lis1[i], lis1[j] + 1);
                }
            }
        }

     

        int lis2[n];
        for (int i = n-1; i >=0; i--) {
            lis2[i] = 1;
            for (int j = n-1; j >i; j--) {
                if (nums[j] < nums[i]) {
                    lis2[i] = max(lis2[i], lis2[j] + 1);
                }
            }
        }

        int res = INT_MIN;

        for (int i = 1; i < n-1; i++) {
            if((lis1[i]>1 and lis2[i]>1))
            res = max(res,  (lis1[i] + lis2[i] - 1));
        }

        return n-res;
    }
};


