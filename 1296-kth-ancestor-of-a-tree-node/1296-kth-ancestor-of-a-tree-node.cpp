class TreeAncestor {
public:
    vector<int> child[200001];
    int up[200001][20];
    int n;
    
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        for(int i = 0; i < n; i++) {
            if (parent[i] != -1)
                child[parent[i]].push_back(i);
        }
        binary_lifting(0, -1);
    }

    void binary_lifting(int src, int par) {
        up[src][0] = par;
        for(int i = 1; i < 20; i++) {
            if(up[src][i-1] != -1)
                up[src][i] = up[up[src][i-1]][i-1];
            else
                up[src][i] = -1;
        }

        for(int ch : child[src]) {
            if(ch != par)
                binary_lifting(ch, src);
        }
    }

    int ans(int node, int k) {
        if(node == -1 || k == 0)
            return node;

        for(int i = 19; i >= 0; i--) {
            if(k >= (1 << i)) {
                return ans(up[node][i], k - (1 << i));
            }
        }
        return -1; 
    }
    
    int getKthAncestor(int node, int k) {
        return ans(node, k);
    }
};
