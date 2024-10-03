class Solution {
private:
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        for(int i = 0; i<nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int sz=mp[target].size();
        return (mp[target][rand()%sz]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */