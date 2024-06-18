// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         Trie trie;
//         for (int& x : nums) {
//             trie.insert(x);
//         }


//     }
// };


// class TrieNode {
// public:
//     TrieNode* left;  // Represents bit 0
//     TrieNode* right; // Represents bit 1

//     TrieNode(){
//         left= NULL;
//         right=NULL;
//     }
// };

// class Trie {
// public:
//     TrieNode* root;

//     Trie() {
//         root = new TrieNode();
//     }

//     void insert(int num) {
//         TrieNode* pCrawl = root;
//         ll sum=0;
//         for (int i = 31; i >= 0; i--) {
//             int ith_bit = (num >> i) & 1;

//             if(sum>=m){

//             }
//             if (ith_bit == 0) {
//                 if (!pCrawl->left) {
//                     pCrawl->left = new TrieNode();
//                 }
//                 pCrawl = pCrawl->left;
//             } else {
//                 if (!pCrawl->right) {
//                     pCrawl->right = new TrieNode();
//                 }
//                 pCrawl = pCrawl->right;
//             }
//         }
//     }

//     int maxXor(int num, int m) {
//         int maxXor = 0;
//         TrieNode* pCrawl = root;
//         for (int i = 31; i >= 0; i--) {
//             int ith_bit = (num >> i) & 1;
//             if (ith_bit == 1) {
//                 if (pCrawl->left) {
//                     maxXor += (1 << i);
//                     pCrawl = pCrawl->left;
//                 } else {
//                     pCrawl = pCrawl->right;
//                 }
//             } else {
//                 if (pCrawl->right) {
//                     maxXor += (1 << i);
//                     pCrawl = pCrawl->right;
//                 } else {
//                     pCrawl = pCrawl->left;
//                 }
//             }
//         }
//         return maxXor;
//     }
// };

// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         Trie trie;
//         for (int& x : nums) {
//             trie.insert(x);
//         }

//         int result = 0;

//         for (int& x : nums) {
//             result = max(result, trie.maxXor(x));
//         }
//         return result;
//     }
// };




class Trie {
public:
    struct TrieNode {
        TrieNode* left;  // Represents bit 0
        TrieNode* right; // Represents bit 1

        TrieNode() : left(nullptr), right(nullptr) {}
    };

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
        TrieNode* pCrawl = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0) {
                if (pCrawl->right) {
                    maxXor |= (1 << i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            } else {
                if (pCrawl->left) {
                    maxXor |= (1 << i);
                    pCrawl = pCrawl->left;
                } else {
                    pCrawl = pCrawl->right;
                }
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<pair<int, pair<int, int>>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), -1);
        Trie trie;
        int numsIndex = 0;
        
        for (auto& query : sortedQueries) {
            int mi = query.first;
            int xi = query.second.first;
            int queryIndex = query.second.second;

            while (numsIndex < nums.size() && nums[numsIndex] <= mi) {
                trie.insert(nums[numsIndex]);
                numsIndex++;
            }
            
            if (numsIndex > 0) {
                result[queryIndex] = trie.maxXor(xi);
            }
        }

        return result;
    }
};
