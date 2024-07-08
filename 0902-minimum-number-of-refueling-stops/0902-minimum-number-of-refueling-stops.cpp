class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue< int > pq;
        int n = stations.size();
        long long int curr = startFuel;
        long long int  cnt = 0;
        if(target<=startFuel){
            return 0;
        }
        if (stations.empty() || curr < stations[0][0]) {
            return -1;
        }

        for (int i = 0; i < n; i++) {
            if (curr >= stations[i][0]) {
                pq.push(stations[i][1]);
                continue;
            } else {
               
                while (curr < stations[i][0] && !pq.empty()) {
                    curr += pq.top();
                    pq.pop();
                    cnt++;
                }
                if (curr < stations[i][0]) {
                    return -1;
                }
                pq.push(stations[i][1]);
            }
        }

        while (curr < target && !pq.empty()) {
            curr += pq.top();
            pq.pop();
            cnt++;
        }

        if (curr >= target) {
            return cnt;
        } else {
            return -1;
        }
    }
};
