// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int n= nums.size(); sort(nums.begin(), nums.end());

//         vector<int>presum; int sum=0;
//         for(int i=0; i<n; i++){
//             sum+=nums[i];
//             presum.push_back(sum);
//         }
        
//         int ans=1; 
//         for(int i=1;i<n; i++){
//         int length=i+1;
//         int sumyy=presum[i];
//         int changed_sum=length*nums[i];
//         if(changed_sum-sumyy<=k){ans= max(ans, i+1);}
//         }

//         return ans;

//     }
// };


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long total = 0;
        int left = 0, result = 1;

        for (int right = 0; right < n; ++right) {
            total += nums[right];

            while ((long long)nums[right] * (right - left + 1) > total + k) {
                total -= nums[left];
                ++left;
            }
            
            result = max(result, right - left + 1);
        }

        return result;
    }
};
