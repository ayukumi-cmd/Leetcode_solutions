#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                // Check if (i, j) forms a valid rectangle
                if (x1 <= x2 && y2 <= y1) {
                    bool valid = true;
                    
                    // Check for any point inside the rectangle
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int x = points[k][0];
                        int y = points[k][1];
                        if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (valid) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt-n;
    }
};
