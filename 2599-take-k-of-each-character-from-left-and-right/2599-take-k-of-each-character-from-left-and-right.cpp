class Solution {
public:


 int takeCharacters(string s, int k) {
    int n = s.size();
    
    // Initialize prefix and suffix vectors
    vector<int> pre_a(n + 1, 0), pre_b(n + 1, 0), pre_c(n + 1, 0);
    vector<int> suff_a(n + 1, 0), suff_b(n + 1, 0), suff_c(n + 1, 0);

    // Compute prefix counts
    for (int i = 0; i < n; ++i) {
        pre_a[i + 1] = pre_a[i] + (s[i] == 'a');
        pre_b[i + 1] = pre_b[i] + (s[i] == 'b');
        pre_c[i + 1] = pre_c[i] + (s[i] == 'c');
    }

    // Compute suffix counts
    for (int i = n - 1; i >= 0; --i) {
        suff_a[n - i] = suff_a[n - i - 1] + (s[i] == 'a');
        suff_b[n - i] = suff_b[n - i - 1] + (s[i] == 'b');
        suff_c[n - i] = suff_c[n - i - 1] + (s[i] == 'c');
    }

    // Function to check if we can get at least k of each character with i characters from prefix and j from suffix
    auto canGetK = [&](int i) {
        if (i >= n) return false;
        int j = lower_bound(suff_a.begin(), suff_a.end(), k - pre_a[i]) - suff_a.begin();
        int b = lower_bound(suff_b.begin(), suff_b.end(), k - pre_b[i]) - suff_b.begin();
        int c = lower_bound(suff_c.begin(), suff_c.end(), k - pre_c[i]) - suff_c.begin();
        return j < n && b < n && c < n;
    };

    // Calculate minimum minutes
    int ans = INT_MAX;
    for (int i = 0; i <= n; ++i) {
        if (canGetK(i)) {
            int j = max({lower_bound(suff_a.begin(), suff_a.end(), k - pre_a[i]) - suff_a.begin(),
                         lower_bound(suff_b.begin(), suff_b.end(), k - pre_b[i]) - suff_b.begin(),
                         lower_bound(suff_c.begin(), suff_c.end(), k - pre_c[i]) - suff_c.begin()});
            if (j < n) {
                ans = min(ans, i + j);
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
};