

class Solution {
public:
    bool solve(int m, vector<int>& ch, vector<int>& run, long long budget) {
        deque<int> dq;
        int n = ch.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (i >= m && !dq.empty() && dq.front() == ch[i - m]) {
                dq.pop_front();
            }
            
            while (!dq.empty() && dq.back() < ch[i]) {
                dq.pop_back();
            }
            
            dq.push_back(ch[i]);
            sum += run[i];

            if (i >= m) {
                sum -= run[i - m];
            }

            if (i >= m - 1) {
                long long totalCost = dq.front() + m * sum;
                if (totalCost <=budget) {
                    return true;
                }
            }
        }
        
        return false;
    }

    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int l = 1;
        int h = chargeTimes.size();
        int ans = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (solve(m, chargeTimes, runningCosts, budget)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
};
