class TrieNode {
public:
    TrieNode* left;  // Represents bit 0
    TrieNode* right; // Represents bit 1

    TrieNode() : left(nullptr), right(nullptr) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* pCrawl = root;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0) {
                if (!pCrawl->left) {
                    pCrawl->left = new TrieNode();
                }
                pCrawl = pCrawl->left;
            } else {
                if (!pCrawl->right) {
                    pCrawl->right = new TrieNode();
                }
                pCrawl = pCrawl->right;
            }
        }
    }

    int maxXor(int num) {
        int maxXor = 0;
        TrieNode* pCrawl = root;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 1) {
                if (pCrawl->left) {
                    maxXor += (1 << i);
                    pCrawl = pCrawl->left;
                } else {
                    pCrawl = pCrawl->right;
                }
            } else {
                if (pCrawl->right) {
                    maxXor += (1 << i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int& x : nums) {
            trie.insert(x);
        }

        int result = 0;

        for (int& x : nums) {
            result = max(result, trie.maxXor(x));
        }
        return result;
    }
};
