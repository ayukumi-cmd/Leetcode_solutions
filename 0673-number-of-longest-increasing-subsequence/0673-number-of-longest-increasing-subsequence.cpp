
class Solution {
public:
    vector<pair<int,int>> lisi(vector<int> nums){
        vector<int> lis(nums.size(), 0); // Initialize to 1 instead of 0
        vector<int> lis_count(nums.size(), 0);
        lis[0]=1; 
        lis_count[0]=1;// Initialize to 1 instead of 0
        for(int i = 1; i < nums.size(); i++){
            lis[i]=1;
            
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
            for(int j = 0; j < i; j++){
                if(lis[i] == lis[j] + 1 and nums[i]>nums[j]){
                    lis_count[i] += lis_count[j];  
                }
            }
            if(lis_count[i]==0){lis_count[i]=1;}
        }

        vector<pair<int,int>> vp;
        for(int i = 0; i < nums.size(); i++){ // Use `i < nums.size()` instead of `nums.size()`
            vp.push_back({lis[i], lis_count[i]});
        }
        return vp;
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> lisa = lisi(nums);
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < lisa.size(); i++){ // Use `lisa.size()` instead of `n`
           maxi = max(maxi, lisa[i].first);
        }
        for(int i = 0; i < lisa.size(); i++){ // Use `lisa.size()` instead of `n`
            if(maxi == lisa[i].first){
                cnt += lisa[i].second;
            }
        }
        return cnt;
    }
};
