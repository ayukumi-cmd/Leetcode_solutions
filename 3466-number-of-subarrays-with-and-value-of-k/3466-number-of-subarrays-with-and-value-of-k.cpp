class Solution {
public:
    long long findval(vector<vector<long long>>& vp) {
        long long Val = 0;
        for (int i = 0; i < 32; i++) {
            if (vp[i][0] == 0) {
                Val += pow(2LL, i);  
            }
        }
        return Val;
    }

    long long count(vector<int>& nums, long long targetval) {
        vector<vector<long long>> vp(32, vector<long long>(2, 0));
        long long count = 0;
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
            long long current = findval(vp);

            while (current <targetval && i <=j) {
                for (int k = 0; k < 32; k++) {
                    int mask = (nums[i] & (1 << k));
                    if (mask == 0) {
                        vp[k][0]--;
                    } else {
                        vp[k][1]--;
                    }
                }
                current = findval(vp);
                i++;
            }

            if (current>=targetval) {
                count +=(j-i+1);
            }
        }

        return count;
    }
long long countSubarrays(vector<int>& nums, long long targetval){
  return count(nums, targetval)-count(nums, targetval+1);
}

};
