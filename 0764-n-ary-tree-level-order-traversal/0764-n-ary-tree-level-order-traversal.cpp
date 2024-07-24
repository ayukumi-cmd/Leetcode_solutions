

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> ret;

            for (int i = 0; i < sz; ++i) {
                Node* el = q.front();
                q.pop();
                ret.push_back(el->val);

                for (auto &child : el->children) {
                    q.push(child);
                }
            }

            ans.push_back(ret);
        }

        return ans;
    }
};
