int mod=300000000;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     int n=nums.size();unordered_map<int,int>mp; int sum=0;int res=0;
     int x= mod%k;
     mod=mod-x;
        for(int i=0; i<n; i++){
           sum+=nums[i];
           mp[(sum+mod)%k]++;
        }
        for(auto el:mp){
           int ans=((el.second-1)*el.second)/2;
           res+=ans;
           if(el.first==0){res+=el.second;}
        } 
        return res;

    }
};