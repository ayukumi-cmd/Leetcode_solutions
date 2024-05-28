class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int n= nums.size();
        for(int i =0;i<n;i++)
        {
            int len =1;
            int temp = nums[i];
           
            for(int j =i;j<n-1;j++)// this loop will not run more than 30 times
            // after 30 iteration there will be atleast 2 numbers whose and will be non zero
            {
                if((temp xor nums[j+1])== temp+nums[j+1])
                {
                    temp+=nums[j+1];
                    len++;
                }
                else
                    break;
                    
            }
            ans=max(len,ans);
        }
        return ans;
    }
};