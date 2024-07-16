
class Solution {
public:
    TreeNode*solve(TreeNode* root, int  p, int q){
        if(root ==NULL || root->val==p || root->val==q){
            return root;
        }

        TreeNode*left= solve(root->left, p, q);
        TreeNode*right=solve(root->right, p, q);
        if(left==NULL){
            return right; 
        }
        if(right==NULL){
            return left;
        }

        else {
            return root;
        }
    }

     bool getPath(TreeNode* root, int node, vector<char>& path) {
        if (root == NULL) return false;

        if (root->val == node) return true;

        path.push_back('L');
        if (getPath(root->left, node, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, node, path)) return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = solve(root, startValue, destValue);

        vector<char> pathToStart, pathToDest;
        getPath(lca, startValue, pathToStart);
        getPath(lca, destValue, pathToDest);

        string result(pathToStart.size(), 'U');
        for (char c : pathToDest) {
            result += c;
        }

        return result;
    }

};