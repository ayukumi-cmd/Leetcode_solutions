class Solution {
public:
  vector<int>dp;
   int solve(vector<int>&energy, int i, int k ){
    if(i>=energy.size()){return 0;}
    if(dp[i]!=1e9){ return dp[i];}
    dp[i]=energy[i]+solve(energy, i+k, k);
    return dp[i];

   }
    
    int maximumEnergy(vector<int>& energy, int k) {
        // int ans= INT_MIN;
        // for(int i=0; i<energy.size(); i++){
        //     int sum=0;
        //     for(int j=i; j<energy.size(); j+=k){
        //     sum+=energy[j];
        //     }
        //     ans= max(ans, sum);
       dp.resize(energy.size()+1, 1e9);
       int ans=INT_MIN;
       for(int i=0; i<energy.size(); i++){
       ans= max(ans, solve(energy, i, k));
       }
       return ans;


        

    }
};