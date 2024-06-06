class Solution {
public:


    long long sumofSubarrayrange(vector<int>& arr) {
        int n = arr.size();
        vector<long long> lefts(n, 0), rights(n, 0);
        vector<long long> leftm(n, 0), rightm(n, 0);
        stack<pair<int, long long>> sLeft, sRight;
        stack<pair<int, long long>> mLeft, mRight;
        
        for(int i = 0; i < n; i++) {
            long long cnt = 1;
            while(!sLeft.empty() && sLeft.top().first > arr[i]) {
                cnt += sLeft.top().second;
                sLeft.pop();
            }
            sLeft.push({arr[i], cnt});
            lefts[i] = cnt;
        }

        for(int i = n - 1; i >= 0; i--) {
            long long cnt = 1;
            while(!sRight.empty() && sRight.top().first >= arr[i]) {
                cnt += sRight.top().second;
                sRight.pop();
            }
            sRight.push({arr[i], cnt});
            rights[i] = cnt;
        }

        for(int i = 0; i < n; i++) {
            long long cnt = 1;
            while(!mLeft.empty() && mLeft.top().first <= arr[i]) {
                cnt += mLeft.top().second;
                mLeft.pop();
            }
            mLeft.push({arr[i], cnt});
            leftm[i] = cnt;
        }

        for(int i = n - 1; i >= 0; i--) {
            long long cnt = 1;
            while(!mRight.empty() && mRight.top().first < arr[i]) {
                cnt += mRight.top().second;
                mRight.pop();
            }
            mRight.push({arr[i], cnt});
            rightm[i] = cnt;
        }

        long long ans1 = 0;
        for(int i = 0; i < n; i++) {
            ans1 = (ans1 + arr[i] * ((leftm[i] * rightm[i]) - (lefts[i] * rights[i])));
        }

        return ans1;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumofSubarrayrange(nums);
    }
};
