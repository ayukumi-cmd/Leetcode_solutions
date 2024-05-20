class Solution {
public:
    vector<int> PrevSmaller(vector<int> &arr, int n) {
        stack<int> S;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!S.empty() && arr[S.top()] >= arr[i]){  S.pop();  }  
            if (S.empty()){ans[i] = -1;}
            else ans[i] = S.top();
            S.push(i);
        }
        return ans;
    }

    vector<int> nextsmaller(vector<int> &arr, int n) {
        stack<int> S;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!S.empty() && arr[S.top()] >= arr[i]){S.pop();}
            if (S.empty()){ans[i] = n;}
            else ans[i] = S.top();
            S.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevs = PrevSmaller(heights, n);
        vector<int> nexts = nextsmaller(heights, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nexts[i] - prevs[i] - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
};
