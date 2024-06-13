
using namespace std;

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<4901> p;
        p[0] = 1;  // Proper initialization of bitset
        
        for (auto& row : mat) {
            bitset<4901> pp;
            for (int i : row) {
                pp |= (p << i);  // Shift p by i and OR it with pp
            }
            swap(pp, p);  // Swap pp into p
        }
        
        int res = INT_MAX;
        for (int i = 1; i < 4901; i++) {
            if (p[i]) {
                res = min(res, abs(i - target));
            }
        }
        return res;
    }
};
