

class Solution {
public:
    bool solve(vector<int>& weights, int mid, int days) {
        int consecutive_days=0;
        int consecutive_sum= 0;
    
        for (int i = 0; i < weights.size(); i++) {
        
           if(weights[i]+consecutive_sum<=mid){
             consecutive_sum=weights[i]+consecutive_sum;
           }
           else {
            consecutive_days++;
            consecutive_sum=weights[i];
           }
          
        }
        if(consecutive_sum!=0){consecutive_days++;}
        return  (consecutive_days<=days);
    }

     int shipWithinDays(vector<int>& weights, int days) {
        
        int start_cap = *max_element(begin(weights), end(weights)); 
        int n=weights.size();
        int end_cap = *max_element(begin(weights), end(weights))*n;

        int mincap = -1;

        while (start_cap <= end_cap) {
            int mid_cap= start_cap + (end_cap - start_cap)/2;

            if (solve(weights, mid_cap , days)) {
                mincap = mid_cap;
                end_cap = mid_cap - 1;
            } else {
                start_cap = mid_cap + 1;
            }
        }

        return mincap;
    }
};
