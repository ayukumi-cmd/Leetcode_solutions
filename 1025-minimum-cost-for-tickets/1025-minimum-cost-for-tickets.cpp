class Solution {
private:
    vector<int>dp;
    int solve(int i,vector<int>& days, vector<int>& costs){
        if(i>=days.size()){
            return 0;
        }
        else if(dp[i]!=-1){
            return dp[i];
        }
        int res=2e9;

        int cur=days[i];
        res=min(res,costs[2]+solve(upper_bound(days.begin()+i,days.end(),cur+30-1)-days.begin(),days,costs));
        res=min(res,costs[1]+solve(upper_bound(days.begin()+i,days.end(),cur+7-1)-days.begin(),days,costs));
        res=min(res,costs[0]+solve(i+1,days,costs));

        return dp[i]=res;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.clear();
        dp.resize(days.size()+1,-1);
        return solve(0,days,costs);
    }
};