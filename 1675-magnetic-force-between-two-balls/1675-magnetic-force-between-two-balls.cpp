class Solution {
public:
    bool canPlaceBalls(vector<int> &position, int dist, int balls) {
        int n = position.size();
        int cntBalls = 1;
        int last = position[0];
        for (int i = 1; i < n; i++) {
            if (position[i] - last >= dist) {
                cntBalls++;
                last = position[i];
            }
            if (cntBalls >= balls) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int> &position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low=1;
        int  high = position[n - 1] - position[0];
        int ans=0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canPlaceBalls(position, mid, m) == true) {
                ans=mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
