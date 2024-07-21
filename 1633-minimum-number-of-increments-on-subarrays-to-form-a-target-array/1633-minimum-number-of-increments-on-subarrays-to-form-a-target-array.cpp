
class Solution {
public:
 int minNumberOperations(vector<int>& target) {
    vector<int>nums(target.size(), 0);
        int n = nums.size();

        int result = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i] - nums[i];

            //sign change ?
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                result += abs(curr);
            } else if(abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }

            prev = curr;
        }

        return result;
    }
};
