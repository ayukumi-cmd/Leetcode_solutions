class Solution {
public:
    int findval(vector<vector<int>>& vp) {                          // Needs the <int> type
        int Val = 0;
        for (int i = 0; i < 32; i++) {
            if (vp[i][0] == 0) {
                Val += pow(2, i);
            }
        }
        return Val;
    }

    int minimumDifference(vector<int>& nums, int targetval) {
        vector<vector<int>> vp(32, vector<int>(2, 0));
        int minDiff = INT_MAX;
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 32; k++) {
                int mask = (nums[j] & (1 << k));
                if (mask == 0) {
                    vp[k][0]++;
                } else {
                    vp[k][1]++;
                }
            }
            int current = findval(vp);
            minDiff = min(minDiff, abs(targetval - current));

            while (current < targetval && i<j) {                    // Changed both conditionals
                                                                    // Only need when curr < k
                for (int k = 0; k < 32; k++) {                      //   because curr increases when
                    int mask = (nums[i] & (1 << k));                //   i is moved up, so answers
                    if (mask == 0) {                                //   will only get worse
                        vp[k][0]--;                                 // Also, i < j, not i <= j,
                    } else {                                        //   because we can't have an
                        vp[k][1]--;                                 //   empty sub-array
                    }
                }
                current = findval(vp);                              // Calculate and check only
                minDiff = min(minDiff, abs(targetval- current));    //   after the change is done
                i++;
            }
        }

//         while (i < n) {                                          // Unnecessary since any
//             minDiff = min(minDiff, abs(targetval- findval(vp))); //   useful values of i already
                                                                    //   checked in last while loop
//             for (int k = 0; k < 32; k++) {                       //   of main for loop
//                 int mask = (nums[i] & (1 << k));
//                 if (mask == 0) {
//                     vp[k][0]--;
//                 } else {
//                     vp[k][1]--;
//                 }
//             }
//             i++;
//         }

//         for(auto el:nums){                                       // Unnecessary, already checked
//              minDiff=min( minDiff, abs(targetval-el));           //   in first part of main
//         }                                                        //   for loop whenever j = i

        return minDiff;
    }
};