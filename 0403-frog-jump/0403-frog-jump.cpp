class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> nums;
    int n = 0;
    map<pair<int,int>, bool>memo;

    bool solve(int idx, int k) {
        if (idx == n - 1) {
            return true;
        }
        pair<int, int>x= make_pair(idx, k);
        if(memo.find(x)!=memo.end()){
            return memo[x];
        }
        for (int i = k - 1; i <= k + 1; i++) {
            if (i > 0 && mp.find(i + nums[idx]) != mp.end()) {
                if (solve(mp[i + nums[idx]], i)) {
                    memo[x]= true;
                    return true;
                }
            }
        }
        memo[x]=false;

        return false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        nums = stones;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
         
        return solve(0, 0);
    }
};
