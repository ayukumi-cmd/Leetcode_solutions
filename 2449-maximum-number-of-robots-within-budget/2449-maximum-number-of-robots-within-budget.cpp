// class Solution {
// public:
//     bool solve(int m , vector<int>& ch, vector<int>& run, long long budget){
//         deque<int>dq;
//         int n= ch.size();  int sum=0;
//         for(int i=0; i<n; i++){
//             if(i>=m and ch[i-m]==dq.front() and !dq.empty()){
//                dq.pop_front();
//             }
//             while(!dq.empty() and dq.back()<ch[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(ch[i]);
//             int maxi=0;
//             if(i>=m-1){
//                  maxi=dq.front();
//             }
//             sum+=run[i];
//             if(i>=m){
//                 sum-=run[i-m];
//             }
//             int x= 0;
//             if(i>=m-1){
//                 x=m*sum;
//             }

//             if((maxi+x)>=budget){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
//         int l= 1; 
//         int h=chargeTimes.size();  int ans= 0;
//         while(l<=h){
//             int m=l+(h-l)/2; 
//             if(solve(m, chargeTimes, runningCosts, budget)){
//                 ans=m; 
//                 l= m+1;
//             }
//             else {
//                 h= m-1;
//             }
//         }
//         return ans;

//     }
// };


// class Solution {
// public:
//     bool solve(int m, vector<int>& ch, vector<int>& run, long long budget) {
//         deque<int> dq;
//         int n = ch.size();
//         long long sum = 0;

//         for (int i = 0; i < n; i++) {
//             if (i >= m && !dq.empty() && dq.front() == ch[i - m]) {
//                 dq.pop_front();
//             }
            
//             while (!dq.empty() && dq.back() < ch[i]) {
//                 dq.pop_back();
//             }
            
//             dq.push_back(ch[i]);
//             sum += run[i];

//             if (i >= m) {
//                 sum -= run[i - m];
//             }

//             if (i >= m - 1) {
//                 long long totalCost = dq.front() + m * sum;
//                 if (totalCost > budget) {
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }

//     int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
//         int l = 1;
//         int h = chargeTimes.size();
//         int ans = 0;

//         while (l <= h) {
//             int m = l + (h - l) / 2;
//             if (solve(m, chargeTimes, runningCosts, budget)) {
//                 ans = m;
//                 l = m + 1;
//             } else {
//                 h = m - 1;
//             }
//         }

//         return ans;
//     }
// };
class Solution{
public:
bool canRunKRobots(int k, const vector<int>& chargeTimes, const vector<int>& runningCosts, long long budget) {
    int n = chargeTimes.size();
    deque<int> dq;
    long long running_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        // Maintain the deque for max chargeTimes
        while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // Add running cost to the current window sum
        running_sum += runningCosts[i];
        
        // When window size exceeds k, slide the window
        if (i >= k) {
            running_sum -= runningCosts[i - k];
            if (dq.front() == i - k) {
                dq.pop_front();
            }
        }
        
        // Check if the total cost is within budget
        if (i >= k - 1) {
            int max_charge = chargeTimes[dq.front()];
            long long total_cost = max_charge + k * running_sum;
            if (total_cost <= budget) {
                return true;
            }
        }
    }
    
    return false;
}

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int n = chargeTimes.size();
    int left = 1, right = n;
    int answer = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canRunKRobots(mid, chargeTimes, runningCosts, budget)) {
            answer = mid;  // This mid value of k is possible
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}
};