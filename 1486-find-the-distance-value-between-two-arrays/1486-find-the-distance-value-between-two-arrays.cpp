
class Solution {
public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
       sort(B.begin(), B.end());
        int ans = 0;
        for (int n : A) {
            if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) ++ans;
        }
        return ans;
    }
};