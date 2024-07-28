class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
     int n=nums.size();

     int sum=0; int sum_1dig=0;

     for(int i=0;i<n; i++){
        sum+=nums[i];

        if(nums[i]/10==0){sum_1dig+=nums[i];}
     }

     int sum_2dig=sum-sum_1dig;


     return sum_2dig!=sum_1dig;   
    }
};