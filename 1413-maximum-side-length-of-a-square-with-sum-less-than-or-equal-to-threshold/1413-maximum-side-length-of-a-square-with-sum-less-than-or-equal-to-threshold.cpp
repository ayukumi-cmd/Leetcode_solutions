class Solution {
public:
    int target;
    void make(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i - 1 >= 0)
                    mat[i][j] += mat[i - 1][j];
                if (j - 1 >= 0)
                    mat[i][j] += mat[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0)
                    mat[i][j] -= mat[i - 1][j - 1];
            }
        }
    }


    bool Maximum_Sum(vector<vector<int>>& mat, int K) {
        int N = mat.size();
        int M = mat[0].size();
        for (int i = K - 1; i < N; i++) {
            for (int j = K - 1; j < M; j++) {
                int local = mat[i][j];
                if (i - K >= 0)
                    local -= mat[i - K][j];
                if (j - K >= 0)
                    local -= mat[i][j - K];
                if (i - K >= 0 && j - K >= 0)
                    local += mat[i - K][j - K];
                if (local <= target) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }
        make(mat); 
        target = threshold;
        int l = 1; 
        int h = min(mat.size(), mat[0].size());
        int ans = 0; 
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (Maximum_Sum(mat, mid)) {
                ans = mid; 
                l = mid + 1; 
            } else {
                h = mid - 1; 
            }
        }
        return ans; 
    }
};
