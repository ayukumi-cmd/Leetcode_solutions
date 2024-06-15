

// class Solution {
// public:
//     static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
//         return a.first > b.first;  
//     }

//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size();
//         vector<pair<int, int>> vp;

//         for (int i = 0; i < n; i++) {
//             vp.push_back({nums2[i], nums1[i]});
//         }

//         sort(vp.begin(), vp.end(), cmp);

//         priority_queue<int, vector<int>, greater<int>> pq;
//         long long sum = 0;
//         long long ans = 0;

//         for (int i = 0; i < n; i++) {
//             int num1 = vp[i].second;
//             int num2 = vp[i].first;

//             sum += num1;
//             pq.push(num1);

//             if (pq.size() > k) {
//                 sum -= pq.top();
//                 pq.pop();
//             }

//             if (pq.size() == k) {
//                 ans = max(ans, sum * num2);
//             }
//         }

//         return ans;
//     }
// };

// using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }


    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }
        sort(vp.begin(), vp.end(), cmp);

        // Use a min-heap to keep the top k largest elements
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            sum += vp[i].second;
            pq.push(vp[i].second);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * vp[i].first);
            }
        }

        return ans;
    }
};