class Trienode {
public:
    unordered_map<char, Trienode*> child;
    Trienode(){}
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trienode* root = new Trienode();

        for (int x : arr1) {
            string word = to_string(x);
            Trienode* curr = root;
            for (char c : word) {
                if (curr->child.find(c) == curr->child.end()) {
                    curr->child[c] = new Trienode();
                }
                curr = curr->child[c];
            }
           
        }

        int ans = 0;
        for (int x : arr2) {
            string word = to_string(x);
            Trienode* curr = root;
            int cnt = 0;
            for (char c : word) {
                if (curr->child.find(c) == curr->child.end()) {
                    break;
                }
                curr = curr->child[c];
                cnt++;
           
                    ans = max(ans, cnt);
              
            }
        }

        return ans;
    }
};
