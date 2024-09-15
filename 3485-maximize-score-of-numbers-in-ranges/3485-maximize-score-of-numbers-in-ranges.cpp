#define ll long long 

class Solution {
public:
    vector<vector<ll>> v;


    bool solve(int mid) {
        ll prev = v[0][0];
        
        for (int i = 0; i < v.size(); i++) {
            ll start = v[i][0];
            ll end = v[i][1];
            
            if (prev > end) {
                return false; 
            }

            if (prev < start) {
                prev = start;
            }
            prev += mid; 
        }
        
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());  
        v.clear();  

       
        for (int i = 0; i < start.size(); i++) {
            v.push_back({start[i], start[i] + d});
        }

         ll  l = 0, h = start[start.size()-1]-start[0]+d;
        ll ans = INT_MIN;


        while (l <= h) {
            ll m = l + (h - l) / 2;  
            if (solve(m)) {
                ans = max(ans, m); 
                l = m + 1;  
            } else {
                h = m - 1; 
            }
        }

        return ans;
    }
};
