class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int,int>mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int ans=INT_MIN;

        for(int i=0; i<nums.size(); i++){
          int res=0;
          long long  num= nums[i];
          
          while(mp.find(num)!=mp.end()){
        

            mp[num]--;
            if(mp[num]==0){mp.erase(num);}
            res++; num=num*num;
            
            
          }
          ans= max(ans, res);
        }


        return ans>=2?ans:-1;
    }
};