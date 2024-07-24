/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
   
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int swaps=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            swaps++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return swaps;

    }
     int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL){return {};}
        q.push(root);
       
         int ans=0;
        while(!q.empty()){
            int sz= q.size();
            vector<int>ret;

            for(int i=0; i<sz; i++){
            TreeNode* el=q.front(); q.pop();
            int x= el->val;
             ret.push_back(x);

             if(el->left){q.push(el->left);}
             if(el->right){q.push(el->right);}
            }
            ans+=minSwaps(ret);
             
        }

        return ans;
    }
};