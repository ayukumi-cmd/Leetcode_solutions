

typedef pair<int, int> p;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), -1);
        unordered_map<int, vector<p>> cases;

        for (int qIdx = 0; qIdx < queries.size(); qIdx++) {
            int i = queries[qIdx][0];
            int j = queries[qIdx][1];

            if (i == j) {
                res[qIdx] = i;
            } else if (i < j && heights[i] < heights[j]) {
                res[qIdx] = j;
            } else if (j < i && heights[j] < heights[i]) {
                res[qIdx] = i;
            } else {
                cases[max(i, j)].push_back(make_pair(max(heights[i], heights[j]), qIdx));
            }
        }

        priority_queue<p, vector<p>, greater<p>> minHeap;
        for (int hIdx = 0; hIdx < heights.size(); hIdx++) {
            int currHeight = heights[hIdx];
            while (!minHeap.empty() && minHeap.top().first < currHeight) {
                int qIdx = minHeap.top().second;
                res[qIdx] = hIdx;
                minHeap.pop();
            }

            for (p& curr : cases[hIdx]) {
                minHeap.push(curr);
            }
        }

        return res;
    }
};
