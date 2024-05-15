class Solution {
private:
    int manhattan(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    pair<int, int> maxManhattanDistance(vector<vector<int>>& points, int remove ) {
        int n = points.size();
        int maxSum = INT_MIN, minSum = INT_MAX, maxDiff = INT_MIN, minDiff = INT_MAX;
        int maxSumIndex, minSumIndex, maxDiffIndex, minDiffIndex;
        for (int i = 0; i < n; i++) {
            if (i != remove) {
                int sum = points[i][0] + points[i][1],
                    diff = points[i][0] - points[i][1];
                if (sum > maxSum) {
                    maxSumIndex = i;
                    maxSum = sum;
                }
                if (sum < minSum) {
                    minSumIndex = i;
                    minSum = sum;
                }
                if (diff > maxDiff) {
                    maxDiffIndex = i;
                    maxDiff = diff;
                }
                if (diff < minDiff) {
                    minDiffIndex = i;
                    minDiff = diff;
                }
            }
        }
      return (max(maxSum - minSum, maxDiff - minDiff) == (maxSum - minSum)) ? make_pair(maxSumIndex, minSumIndex) : make_pair(maxDiffIndex, minDiffIndex);

    }
    
public:
    int minimumDistance(vector<vector<int>>& points) {
        pair<int, int>p= maxManhattanDistance(points, -1);
        pair<int, int>q= maxManhattanDistance(points, p.first);
        pair<int, int>r= maxManhattanDistance(points, p.second);
        return min({manhattan(points, p.first, p.second),manhattan(points,  q.first, q.second),manhattan(points,  r.first, r.second)});
    }
};