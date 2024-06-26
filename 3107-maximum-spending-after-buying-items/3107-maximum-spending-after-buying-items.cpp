
class Solution {
public:

    long long maxSpending(vector<vector<int>>& values) {
     vector<long long>val;
     for(int i=0; i<values.size(); i++){
        for(int j=0; j<values[0].size(); j++){
            val.push_back(values[i][j]);
        }
     }
     sort(val.begin(), val.end());

     long long d=1;
     long long ans=0;
     for(int i=0; i<val.size(); i++){
        ans+=(d*val[i]); d++;
     }
     return ans;
    }
};