class Solution {
public:

    vector<bool> isprime(int n) {
        vector<bool> f(n + 1, false);
        for (int i = 2; i <= n; i++) {
            if (!f[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    f[j] = true;
                }
            }
        }
        return f;
    }


    vector<vector<int>> prime(vector<int>& nums) {
        vector<bool> f = isprime(1001);  
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            for (int el = 2; el < nums[i]; el++) {  
                if (!f[el]) {
                    temp.push_back(el);
                }
            }
            res.push_back(temp);
        }
        return res;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> primes = prime(nums);  

        int prev = 0;  
        for (int i = 0; i < n; i++) {
            int current = nums[i];
            bool found = false;
            if(current>prev){found=true;}
   
            int left = 0, right = primes[i].size() - 1, bestPrime = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int primeCandidate = primes[i][mid];
                
                if (current - primeCandidate > prev) {
                    bestPrime = primeCandidate;
                    left = mid + 1;
                    found = true;
                } else {
                    right = mid - 1;
                }
            }

            if (!found) {
                return false;
            }

            prev = current - bestPrime;
        }

        return true;
    }
};
