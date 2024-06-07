class Solution {
public:
    bool issorted(vector<int>&nums){
        bool ans=true;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                ans=false; break;
            }
        }
        return ans;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                vector<int>temp;
                for(int k=0; k<i; k++){
                    temp.push_back(nums[k]);
                }
                for(int k=j+1; k<n; k++){
                    temp.push_back(nums[k]);
                }
                if(issorted(temp)){
                    ans+=(n-j);
                    break;
                }
               temp.clear();
            }
        }
        return  ans;
    }
};