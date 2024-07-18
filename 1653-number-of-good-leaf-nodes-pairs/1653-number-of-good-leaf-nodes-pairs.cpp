
class Solution {
public:
int findGoodLeafPairs(TreeNode* root, int distance, vector<int>& depths) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        depths.push_back(0);
        return 0;
    }

    vector<int> leftDepths, rightDepths;
    int left = findGoodLeafPairs(root->left, distance, leftDepths);
    int right = findGoodLeafPairs(root->right, distance, rightDepths);
    
    int goodPairs = 0;
    for (int lDepth : leftDepths) {
        for (int rDepth : rightDepths) {
            if (lDepth + rDepth + 2 <= distance) {
                goodPairs++;
            }
        }
    }

    for (int& lDepth : leftDepths) {
        depths.push_back(lDepth + 1);
    }
    for (int& rDepth : rightDepths) {
        depths.push_back(rDepth + 1);
    }

    return goodPairs + left + right;
}

    int countPairs(TreeNode* root, int distance) {
    vector<int> depths;
    return findGoodLeafPairs(root, distance, depths);
}
};