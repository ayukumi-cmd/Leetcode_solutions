class Solution {
public:
     const int MOD = 1e9 + 7;
    int dp[2][2][30][420];
    int countnum(bool tight1, bool tight2 , int idx, int sum, string &num1, string &num2){
        if(sum<0){return 0;}
        if(idx==num2.size()){return 1;}
        if(dp[tight1][tight2][idx][sum]!=-1){return dp[tight1][tight2][idx][sum];}
        int lowest_possible_on_idx=tight1?num1[idx]-'0':0;
        int highest_possible_on_idx=tight2?num2[idx]-'0':9;
        int count=0;
        for(int i=lowest_possible_on_idx; i<=highest_possible_on_idx; i++){
         count=(count% MOD+countnum(tight1&(i==lowest_possible_on_idx),tight2&(i==highest_possible_on_idx),idx+1, sum-i, num1, num2)% MOD)% MOD;
        }
        return dp[tight1][tight2][idx][sum]=count;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int size_diff=num2.length()-num1.length();
        string modified_num1;
        for(int i=0; i<size_diff; i++){modified_num1+='0';}
        modified_num1+=num1;
        int inclusion=countnum(1, 1,0,max_sum,modified_num1, num2);
        int exclusion=countnum(1, 1,0, min_sum-1,modified_num1, num2);
        return (inclusion-exclusion+MOD)% MOD;

    }
};