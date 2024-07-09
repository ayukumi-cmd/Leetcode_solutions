class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        long long int prev=customers[0][0];
        long long int  time =0;

        for(int i=0; i<customers.size(); i++){
          long long int  x=max(prev-customers[i][0], 0LL);
          
          prev=(customers[i][0]+x+customers[i][1]);
          time+=(x+customers[i][1]);
        }


        double ans= static_cast<double>(time)/static_cast<double>(n);
        return ans;
    }
};