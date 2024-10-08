class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mp; 
        if(intervals.size()==1){return 1;}

        for(int i=0; i<intervals.size(); i++){
            mp[intervals[i][0]]++;
            mp[intervals[i][1]+1]--;
        }
        int ans=INT_MIN; int cnt=0;
        for(auto &it:mp){
            cnt+=it.second;
            ans= max(ans, cnt);
        }
        return ans;
        
    }
};