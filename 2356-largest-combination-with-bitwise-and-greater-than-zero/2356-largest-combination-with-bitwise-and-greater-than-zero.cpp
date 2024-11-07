class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n= nums.size(); 
        int ans=INT_MIN;

        for(int i=0; i<=30; i++){

            int cnt=0;

            for(int j=0; j<n; j++){
               int x= nums[j]&(1<<i);
               if(x!=0){
                cnt++;
               }
            }

            ans= max(ans, cnt);
        }

        return ans;
    }
};