

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    int index; 
    int length;

    TrieNode() {
        index = -1;
        length = INT_MAX; 
    }
    ~TrieNode() {
        for (auto &pair : child) {
            delete pair.second;
        }
    }

};

class Solution {
public:
        vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();

        int small=INT_MAX;
        int idx=-1;
        for(int i=0; i<wordsContainer.size(); i++){
          if(small>wordsContainer[i].length()){
            small=wordsContainer[i].length();
            idx=i;
          }
        }

        for (int i = 0; i < wordsContainer.size(); ++i) {
            const string& word = wordsContainer[i];
            TrieNode* curr = root;
            int wordLength = word.size();
            
            for (int j = wordLength - 1; j >= 0; --j) {
                char c = word[j];
                if (curr->child.find(c) == curr->child.end()) {
                    curr->child[c] = new TrieNode(); 
                }
                curr = curr->child[c];

           
                if (curr->index == -1 || wordLength < curr->length || (wordLength == curr->length && i < curr->index)) {
                    curr->index = i; 
                    curr->length = wordLength; 
                }
            }
        }

        vector<int> ans;

        for (const string& query : wordsQuery) {
            TrieNode* curr = root;
            int queryLength = query.size();
            int bestMatchIndex = -1;

            for (int j = queryLength - 1; j >= 0; --j) {
                char c = query[j];
                if (curr->child.find(c) == curr->child.end()) {
                    break;
                }
                curr = curr->child[c];
                bestMatchIndex = curr->index; 
            }

            ans.push_back(bestMatchIndex);
        }

       for(int i=0; i<ans.size(); i++){
        if(ans[i]==-1){ans[i]=idx;}
       }
       delete root;

        return ans;
    }
};
