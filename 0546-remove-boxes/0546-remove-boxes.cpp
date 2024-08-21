class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int size = boxes.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>(size, 0)));
        return get(dp, boxes, 0, size - 1, 0);
    }

private:
    int get(vector<vector<vector<int>>>& dp, vector<int>& boxes, int left, int right, int streak) {
        if (left > right) {
            return 0;
        } else if (left == right) {
            return (streak + 1) * (streak + 1);
        } else if (dp[left][right][streak] != 0) {
            return dp[left][right][streak];
        } else {
            int maxi = get(dp, boxes, left + 1, right, 0) + (streak + 1) * (streak + 1);

            for (int i = left + 1; i <= right; i++) {
                if (boxes[left] == boxes[i]) {
                    maxi = max(maxi, get(dp, boxes, left + 1, i - 1, 0) + get(dp, boxes, i, right, streak + 1));
                }
            }

           return dp[left][right][streak] = maxi;
           
        }
    }
};
