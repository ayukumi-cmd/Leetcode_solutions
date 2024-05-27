using namespace std;

struct SegmentTree {
    vector<int> tree;
    int N;
    int length;

    SegmentTree(vector<int>& v) {
        N = v.size();
        length = 4 * N;
        tree.resize(length, INT_MIN);
        build(v, 1, 0, N - 1);
    }

    void build(vector<int>& v, int x, int left, int right) {
        if (left == right) {
            tree[x] = v[left];
            return;
        }
        int mid = (left + right) / 2;
        build(v, 2 * x, left, mid);
        build(v, 2 * x + 1, mid + 1, right);
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }

    void update(int x, int left, int right, int index, int value) {
        if (left == right) {
            tree[x] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (index > mid) {
            update(2 * x + 1, mid + 1, right, index, value);
        } else {
            update(2 * x, left, mid, index, value);
        }
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }

    int find(int x, int left, int right, int k) {
        if (left == right) {
            return left;
        }
        int mid = (left + right) / 2;
        if (k <= tree[2 * x]) {
            return find(2 * x, left, mid, k);
        } else {
            return find(2 * x + 1, mid + 1, right, k - tree[2 * x]);
        }
    }
};

class Solution {
public:
    static bool compare(vector<int>& u, vector<int>& v) {
        if (u[0] < v[0]) return true;
        if (u[0] > v[0]) return false;
        return u[1] > v[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> result(n, vector<int>{2, 0});

        vector<int> v(n, 1);
        SegmentTree sgTree(v); 
        int index;
        
        for (int i = 0; i < n; i++) {
            index = sgTree.find(1, 0, n - 1, people[i][1] + 1);    
            result[index][0] = people[i][0];
            result[index][1] = people[i][1];
            sgTree.update(1, 0, n - 1, index, 0);
        }
        
        return result;
    }
};
