class Solution {
public:


vector<int> pre_a, pre_b, pre_c;
vector<int> suff_a, suff_b, suff_c;

bool canGetK(int i, int k) {
    if (i >= suff_a.size()) return false;
    int j_a = lower_bound(suff_a.begin(), suff_a.end(), k - pre_a[i]) - suff_a.begin();
    int j_b = lower_bound(suff_b.begin(), suff_b.end(), k - pre_b[i]) - suff_b.begin();
    int j_c = lower_bound(suff_c.begin(), suff_c.end(), k - pre_c[i]) - suff_c.begin();
    return j_a < suff_a.size() && j_b < suff_b.size() && j_c < suff_c.size();
}

 int takeCharacters(string s, int k) {
    int n = s.size();
    
    pre_a.resize(n + 1);
    pre_b.resize(n + 1);
    pre_c.resize(n + 1);
    suff_a.resize(n + 1);
    suff_b.resize(n + 1);
    suff_c.resize(n + 1);

   
    int total_a = 0, total_b = 0, total_c = 0;
    for (char ch : s) {
        if (ch == 'a') total_a++;
        if (ch == 'b') total_b++;
        if (ch == 'c') total_c++;
    }

  
    if (total_a < k || total_b < k || total_c < k) {
        return -1;
    }


    for (int i = 0; i < n; ++i) {
        pre_a[i + 1] = pre_a[i] + (s[i] == 'a');
        pre_b[i + 1] = pre_b[i] + (s[i] == 'b');
        pre_c[i + 1] = pre_c[i] + (s[i] == 'c');
    }

    
    for (int i = n - 1; i >= 0; --i) {
        suff_a[n - i] = suff_a[n - i - 1] + (s[i] == 'a');
        suff_b[n - i] = suff_b[n - i - 1] + (s[i] == 'b');
        suff_c[n - i] = suff_c[n - i - 1] + (s[i] == 'c');
    }


    int ans = INT_MAX;
    for (int i = 0; i <= n; ++i) {
        if (canGetK(i, k)) {
            int j_a = lower_bound(suff_a.begin(), suff_a.end(), k - pre_a[i]) - suff_a.begin();
            int j_b = lower_bound(suff_b.begin(), suff_b.end(), k - pre_b[i]) - suff_b.begin();
            int j_c = lower_bound(suff_c.begin(), suff_c.end(), k - pre_c[i]) - suff_c.begin();
            int j = max({j_a, j_b, j_c});
            if (j < n) {
                ans = min(ans, i + j);
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
};
