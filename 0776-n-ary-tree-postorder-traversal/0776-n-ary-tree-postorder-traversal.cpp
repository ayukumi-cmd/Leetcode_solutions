void solve(Node*root,vector<int>&ans){
   vector<Node*>child=root->children; 

   for(int i=0; i<child.size(); i++){
      solve(child[i], ans);
   }
   ans.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
    if(root==NULL){return {};}
    vector<Node*>child= root->children; 
    if(child.size()==0){return {root->val};}
    
     vector<int>ans; 
     solve(root, ans);
     return ans;
    }
};