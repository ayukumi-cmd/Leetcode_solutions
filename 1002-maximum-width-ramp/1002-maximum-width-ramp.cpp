class segment {
public:
    int len;
    vector<int> t;
    
    segment(int l) {
        len = l;
        t.resize(4 * l, INT_MAX);
    }

    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) {
            return INT_MAX;
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);
        return min(left, right);
    }

    void update(int v, int tl, int tr, int idx, int val) {
        if ((tl == tr) and tl==idx) {  
            t[v] = val;
            return;
        }
        if(idx>tr|| idx<tl){return ;}
        int tm = (tl + tr) / 2;
        
            update(2 * v, tl, tm, idx, val);
        
            update(2 * v + 1, tm + 1, tr, idx, val);
        
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        segment s(maxi );  

        vector<int> a(maxi + 1, INT_MAX);
        s.build(a, 1, 0, maxi);

        int ans = 0;  
        for (int i = 0; i < nums.size(); i++) {
            int x = s.query(1, 0, maxi, 0, nums[i]); 

            if (x != INT_MAX) {
                ans = max(ans, i - x);  
            }

            if (a[nums[i]] == INT_MAX) {
                s.update(1, 0, maxi, nums[i], i);
                a[nums[i]]=i;
            }

            cout<<ans<<endl;
        }
        return ans;
    }
};

