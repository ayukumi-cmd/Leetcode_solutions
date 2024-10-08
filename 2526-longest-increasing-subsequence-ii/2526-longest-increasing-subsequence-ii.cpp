class segment {
public:
    int len; 
    vector<int> t; 
    segment(int l) {
        len = l;
        t.resize(4 * l);
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) {
            return 0;
        }
        if (l <= tl && r >= tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);
        return max(left, right);
    }

    void update(int v, int tl, int tr, int idx, int val) {
        if (tl == idx && tr == idx) {
            t[v] = val;
            return;
        }
        if (idx < tl || idx > tr) {
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, idx, val);
        update(2 * v + 1, tm + 1, tr, idx, val);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        segment s(maxi);

        vector<int> a(maxi + 1, 0);
        s.build(a, 1, 1, maxi);

        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int maxLengthInRange = s.query(1, 1, maxi, max(1, num - k), num - 1);
            int currentLIS = maxLengthInRange + 1;
            result = max(result, currentLIS);
            s.update(1, 1, maxi, num, currentLIS);
        }

        return result;
    }
};
