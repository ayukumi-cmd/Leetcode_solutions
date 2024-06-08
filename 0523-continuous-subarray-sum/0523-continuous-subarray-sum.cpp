class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(); vector<int>prerem;
        int sum=0; unordered_map<int, int>mp;
        if(n==1){
            return false;
        }
        for(int i=0; i<n; i++){
            sum+=nums[i];
            prerem.push_back(sum%k);
            if(mp.find(sum%k)!=mp.end()){
                if(mp[sum%k]>=2){return true;}
                else {
                    if(i-1>=0 and prerem[i-1]!=sum%k){return true;}
                }
            }
            mp[sum%k]++;
        }
        for(int i=1; i<n; i++){
            if(prerem[i]==0){return true;}
            if((nums[i]+nums[i-1])%k==0){return true;}
        }
 
        return false;


    }
};