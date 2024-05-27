class Solution {
public:
int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // O(NlogN)
    for (int i = 1; i <= nums.size(); i++) { // O(N)
        auto itr = lower_bound(nums.begin(), nums.end(), i); // O(LogN)
        if (distance(itr, nums.end()) == i) return i; // O(1)
    }
    return -1;
}
};