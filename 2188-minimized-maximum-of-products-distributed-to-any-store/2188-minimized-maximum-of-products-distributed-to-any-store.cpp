class Solution {
public:
    bool solve(vector<int>& quantities, long long mid, int n) {
        long long total_stores = 0;
        
        for (int i = 0; i < quantities.size(); i++) {
            long long stores_needed = quantities[i] / mid;
            if (quantities[i] % mid) {
                stores_needed++;
            }
            total_stores += stores_needed;
        }
        
        return (total_stores <= n);
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        long long total_quantity = accumulate(quantities.begin(), quantities.end(), 0LL);
        
        long long start_cap = total_quantity / n;
        if (total_quantity % n) {
            start_cap++;
        }

        long long end_cap = *max_element(begin(quantities), end(quantities));
        
        long long mincap = -1;
        
        while (start_cap <= end_cap) {
            long long mid_cap = start_cap + (end_cap - start_cap) / 2;
            
            if (solve(quantities, mid_cap, n)) {
                mincap = mid_cap;
                end_cap = mid_cap - 1;
            } else {
                start_cap = mid_cap + 1;
            }
        }
        
        return mincap;
    }
};
