class Solution {
public:
    long long dp[1 << 11][1001];
    unordered_map<int, int> hash;

    int primeFactorisation_MASK(int num) {
        int mask = 0;
        if (num % 2 == 0) {
            mask |= (1 << hash[2]);
            while (num % 2 == 0) num /= 2;
        }
        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0) {
                mask |= (1 << hash[i]);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 2) {
            mask |= (1 << hash[num]);
        }
        return mask;
    }

    long long helper(int mask, int curr, const vector<int>& masks) {
        if (curr == masks.size()) {
            return 1;
        }
        if (dp[mask][curr] != -1) {
            return dp[mask][curr];
        }

        long long ACCEPT = 0;
        if ((masks[curr] & mask) == 0) {
            ACCEPT = helper(mask | masks[curr], curr + 1, masks);
        }

        long long IGNORE = helper(mask, curr + 1, masks);

        return dp[mask][curr] = (ACCEPT + IGNORE) % 1000000007;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int primeFactors[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        for (int i = 0; i < 11; i++) {
            hash[primeFactors[i]] = i;
        }

        vector<int> masks;
        for (int x : nums) {
            if (x == 4 || x == 8 || x == 9 || x == 12 || x == 16 || x == 18 ||
                x == 20 || x == 24 || x == 25 || x == 27 || x == 28) {
                continue;
            }
            int mask = primeFactorisation_MASK(x);
            masks.push_back(mask);
        }

        memset(dp, -1, sizeof(dp));
        return (helper(0, 0, masks) - 1 + 1000000007) % 1000000007; 
    }
};
