class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0; 
        for(int i=0; i<nums.size(); i++){sum+=nums[i];}

        int mini= *min_element(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<nums.size(); i++){ans+=(nums[i]-mini);}
        return ans;
    }
};