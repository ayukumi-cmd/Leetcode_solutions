class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return max(left, right) + 1;
    }

    void calculateLevelSum(TreeNode* node, int level, vector<int>& sum) {
        if (node == NULL) {
            return;
        }

        sum[level] += node->val;

        calculateLevelSum(node->left, level + 1, sum);
        calculateLevelSum(node->right, level + 1, sum);
    }

    void solve(TreeNode* root, int level, vector<int>& sum) {
        if (root == NULL) {
            return;
        }

        int x = 0, y = 0;

        if (root->left != NULL) {
            x = root->left->val;
        }
        if (root->right != NULL) {
            y = root->right->val;
        }

        if (root->left != NULL) {
            root->left->val = sum[level + 1] - x - y;
        }

        if (root->right != NULL) {
            root->right->val = sum[level + 1] - x - y;
        }

        solve(root->left, level + 1, sum);
        solve(root->right, level + 1, sum);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        int levels = getHeight(root) + 1;
        vector<int> sum(levels, 0);

        calculateLevelSum(root, 0, sum);

        root->val = 0;
        solve(root, 0, sum);

        return root;
    }
};
