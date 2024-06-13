class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>addval; vector<int>subval;
        int n= values.size();

        for(int i=0; i<n; i++){
            addval.push_back(values[i]+i);
            subval.push_back(values[i]-i);
        }

        map<int, int>mp; 
        for(int i=1; i<subval.size(); i++){    mp[subval[i]]++;    }
        
        int ans=INT_MIN;
        
        for(int i=0; i<addval.size()-1; i++){
         auto it =mp.end();
         it--;
         ans=max(ans, (*it).first+addval[i]);
         if(mp[subval[i+1]]==1){
            mp[subval[i+1]]=0;
            mp.erase(subval[i+1]);
         }
         else{
            mp[subval[i+1]]--;
         }
         
        }
        return ans;
    }
};