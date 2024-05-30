class Solution {
public:
bool hasTrailingZeros(vector<int>& nums) {
    int even = 0;
    for(auto n: nums) even += ((n%2)?0:1);
    return (even >= 2);
}
};