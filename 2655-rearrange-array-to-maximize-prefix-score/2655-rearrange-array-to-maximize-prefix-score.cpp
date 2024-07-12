class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long  n= nums.size();
        sort(nums.begin(), nums.end() , greater<int>());
        
        long long sum=0; long long cnt=0;
        for(int i=0; i<n; i++){
          sum+=nums[i];
          if(sum>0){cnt++;}
        }
        return  cnt;
    }
};