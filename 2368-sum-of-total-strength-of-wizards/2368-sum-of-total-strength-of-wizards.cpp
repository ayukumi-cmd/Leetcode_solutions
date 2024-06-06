#define MOD 1000000007

class Solution {
public:

   long long solve(vector<int>&arr){
    int n=arr.size();
    vector<long long> prefix(n + 1, 0L);
    for (int i = 0; i < n; ++i){
        prefix[i + 1] = (prefix[i] + arr[i]) % MOD;
    }
   
    vector<long long> prefix_sum(n + 2, 0L);
    for (int i = 0; i <= n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
    }
        vector<int> left(n, 0), right(n, 0);
        stack<pair<int, int>> sLeft, sRight;

        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!sLeft.empty() && sLeft.top().first >arr[i]) {
                cnt += sLeft.top().second;
                sLeft.pop();
            }
            sLeft.push({arr[i], cnt});
            left[i] = cnt;
        }

        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!sRight.empty() && sRight.top().first >= arr[i]) {
                cnt += sRight.top().second;
                sRight.pop();
            }
            sRight.push({arr[i], cnt});
            right[i] = cnt;
        }
    long long res = 0;
      
        for (int i = 0; i < n; ++i) {
            int l = left[i];
            int r = right[i];
            
            // Calculate prefix sum ranges
            long long left_sum = (prefix_sum[i + 1] - prefix_sum[i - l + 1] + MOD) % MOD;
            long long right_sum = (prefix_sum[i + r + 1] - prefix_sum[i + 1] + MOD) % MOD;
            
            // Calculate contribution to the result
            long long left_contrib = (left_sum * r) % MOD;
            long long right_contrib = (right_sum * l) % MOD;
            
            res = (res + (right_contrib - left_contrib + MOD) * arr[i]) % MOD;
        }


    return res;

   }
    int totalStrength(vector<int>& strength) {
        return solve(strength);
    }
};