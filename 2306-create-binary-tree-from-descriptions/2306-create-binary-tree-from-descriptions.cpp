class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
        unordered_map<int, TreeNode*> Node;                       
        unordered_map<int, bool> isChild;                               
        for(auto v: descriptions){
            if(Node.count(v[0])==0){
                TreeNode* par = new TreeNode(v[0]);
                Node[v[0]] = par;
            }
            if(Node.count(v[1])==0){
                TreeNode* child = new TreeNode(v[1]);
                Node[v[1]] = child;
            }
            if(v[2]==1) Node[v[0]]->left = Node[v[1]];               
            else Node[v[0]]->right = Node[v[1]];                     
            isChild[v[1]] = true;
        }
        TreeNode* ans = NULL;
        for(auto &v: descriptions){
            if(isChild[v[0]] != true){                  
                ans = Node[v[0]]; 
                break;
            }
        }
        return ans;
    }
};
