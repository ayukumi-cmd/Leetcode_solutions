

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (b.first < a.first) {
            return true;
        } else if (b.first == a.first) {
            return a.second > b.second;
        } else {
            return false;
        }
    }

    int maxPerformance(int n, vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long , long long >> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }

        sort(vp.begin(), vp.end(), cmp);

        priority_queue<long long , vector<long long >, greater<long long >> pq;
        long long sum = 0;
        long long  maxPerformance = 0;
        const int MOD = 1000000007;


        for (int i = 0; i < n; i++) {
            sum += vp[i].second;
            pq.push(vp[i].second);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            maxPerformance = max(maxPerformance, (sum) *( vp[i].first));
        }

        return maxPerformance % MOD;
    }
};


