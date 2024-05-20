

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
           
            if(height>=width){ans= max(ans, width*width);}
            else if(width>height){ans= max(ans, height*height);}
        }
        return ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>hist(col, 0);
        int ans= INT_MIN;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                 if(matrix[i][j]=='0'){ hist[j]=0;}
                 else{ hist[j]=hist[j]+1;}
            }
          ans= max(ans, largestRectangleArea(hist));
        }
        return ans;
    }
};