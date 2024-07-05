
class Solution {
public:
    vector<vector<long long >>dp;
    long long findCombination(long long target, long long i, long long poww, vector<long long> &nums) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (i >= nums.size()) {
            return 0;
        }
        if(dp[target][i]!=-1){return dp[target][i];}
        long long ans = 0;
        long long power = pow(nums[i], poww);
        if (target >= power) {
            ans += findCombination(target - power, i + 1, poww, nums);
        }
        // not take case 
        ans += findCombination(target, i + 1, poww, nums);
        return dp[target][i]=ans;
    }

    int numberOfWays(int n, int x) {
        int num = pow(n, 1.0 / x); 
        vector<long long> nums;
        for (int i = 1; i <= num+1; i++) {
            nums.push_back(i);
        }
        dp.resize(n+1, vector<long long >(num+1, -1));

        return findCombination(n, 0, x, nums)%(1000000007);
    }
};
