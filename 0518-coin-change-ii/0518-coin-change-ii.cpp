
// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

class Solution {
public:
    // Memoization table to store intermediate results
    unordered_map<pair<int, int>, int, pair_hash> dp;

    int change(int x, vector<int>& p) {
        return changeHelper(x, p, p.size());
    }

    int changeHelper(int x, vector<int>& p, int n) {
        // Base cases
        if (x == 0) return 1; // One way to make 0 is by using no coins
        if (x < 0 || n == 0) return 0; // No way to make change if amount is negative or no coins left

        // Create a key for the memoization table
        pair<int, int> key = make_pair(x, n);
        
        // Check if the result is already in the memoization table
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        // Recurrence relation: exclude the current coin or include it and reduce the amount
        int exclude = changeHelper(x, p, n - 1);
        int include = changeHelper(x - p[n - 1], p, n);

        // Store the result in the memoization table
        dp[key] = exclude + include;

        return dp[key];
    }
};