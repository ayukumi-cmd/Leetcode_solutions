const int MOD = 1000000007;

class Solution {
public:
    long long po(long long a, long long n){
        long long res = 1;
        while(n){
            if(n % 2){
               res = (res % MOD * a % MOD) % MOD;
               n--;
            }
            else {
                a = ((a % MOD * a % MOD)) % MOD;
                n = n / 2;
            }
        }
        return res;
    }
    
    long long solve(vector<int>& nums, long long sum, long long k, long long cnt, long long i, vector<vector<vector<long long>>>& dp){
        if(sum == k) return (po(2, nums.size() - cnt)) % MOD;
        if(sum > k || i >= nums.size()) return 0;
        if(dp[sum][i][cnt] != -1) return dp[sum][i][cnt];
        long long x = solve(nums, sum + nums[i], k, cnt + 1, i + 1, dp);
        long long y = solve(nums, sum, k, cnt, i + 1, dp);
        dp[sum][i][cnt] = (x % MOD + y % MOD) % MOD;
        return dp[sum][i][cnt] % MOD;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1)));
        return static_cast<int>(solve(nums, 0, k, 0, 0, dp)); 
    }
};
