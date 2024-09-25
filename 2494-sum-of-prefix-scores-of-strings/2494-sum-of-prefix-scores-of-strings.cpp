

class Trienode {
public:
    unordered_map<char, Trienode*> child;
    int count ;
    Trienode(){
        count =0;
    }
};

class Solution {
public:
     vector<int> sumPrefixScores(vector<string>& words) {
        Trienode* root = new Trienode();

        for (auto  x : words) {
         
            Trienode* curr = root;
            for (char c : x) {
                if (curr->child.find(c) == curr->child.end()) {
                    curr->child[c] = new Trienode();
                }
                curr = curr->child[c];
                curr->count= (curr->count)+1;
            }
           
        }

     

        vector<int>ans;
        for (auto x : words) {
            
            Trienode* curr = root;
            int cnt = 0;
            for (char c : x) {
                if (curr->child.find(c) == curr->child.end()) {
                    break;
                }
                curr = curr->child[c];
                cnt+=curr->count;
           
                 
              
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};
