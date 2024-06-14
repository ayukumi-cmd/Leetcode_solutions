class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n= nums.size();
        int maxi=*max_element(nums.begin(), nums.end());
        vector<int>freq(maxi+n+1);

        for(int i=0; i<nums.size(); i++){freq[nums[i]]++;}

       int extra=0; int ans=0;
       for(int i=0; i<freq.size(); i++){
        if(freq[i]<=1){continue;}

        extra= freq[i]-1;
        ans+=extra;
        freq[i+1]+=extra;

       }
       return  ans;
    }
};