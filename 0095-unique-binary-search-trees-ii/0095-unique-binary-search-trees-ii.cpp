vector<TreeNode*> generateTreesUseRecursion(int start,  int end)
{
    if (start > end)
    {
        return { nullptr };
    }

    vector<TreeNode*> trees;
    for (int i = start; i <= end; ++i)
    {
        for (TreeNode* leftRoot : generateTreesUseRecursion(start, i - 1)) // left child, low..i - 1
        {
            for (TreeNode* rightRoot : generateTreesUseRecursion(i + 1, end)) // right child i+1..high
            {
                TreeNode* root = new TreeNode(i);
                root->left = leftRoot;
                root->right = rightRoot;
                trees.push_back(root);
            }
        }
    }

    return trees;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUseRecursion(1, n);
    }
};