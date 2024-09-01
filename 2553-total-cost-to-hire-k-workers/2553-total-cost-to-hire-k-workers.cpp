class Solution {
public:
    using ll = long long;
    using p = pair<ll, int>;  // Use ll instead of int for the cost
   
    
    ll totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int i = 0;
        int j = n - 1;
        priority_queue<p, vector<p>, greater<p>> pq;
        
        ll ans = 0;
        int hired = 0;
        int s = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        
        while (hired < k) {
            while (i <= j && i < n && cnt1 < candidates && s != 1) {
                pq.push({costs[i], 0});
                i++;
                cnt1++;
            }
            
            while (i <= j && j >= 0 && cnt2 < candidates && s != 0) {
                pq.push({costs[j], 1}); 
                j--;
                cnt2++;
            }
            
            auto mini = pq.top(); 
            ll ele = mini.first;  // Use ll for ele
            int side = mini.second;
            pq.pop();
            ans += ele;
            cout << ele << endl;  // Prints the cost value
            
            if (side == 1) {
                s = 1;
                cnt2--;
            } else {
                s = 0;
                cnt1--;
            }
            hired++;
        }
        return ans;
    }
};
