
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        if (n <= 1) return 0;

        int max_jump = 0; 
        int jumps = 0; 
        int current_end = 0; 

        for (int i = 0; i < n - 1; i++) { 
            max_jump = max(max_jump, i + nums[i]); 
            if (i == current_end) { 
                jumps++; 
                current_end = max_jump; 
            }
        }

        return jumps;
    }
};
