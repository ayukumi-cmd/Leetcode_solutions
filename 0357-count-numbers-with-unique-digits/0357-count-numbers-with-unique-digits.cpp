class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>nums(10); 
        nums[0]=1; 
        nums[1]= nums[0]+9;
        nums[2]= nums[1]+9*9;
        nums[3]= nums[2]+9*9*8;
        nums[4]= nums[3]+9*9*8*7;
        nums[5]= nums[4]+9*9*8*7*6;
        nums[6]= nums[5]+9*9*8*7*6*5;
        nums[7]= nums[6]+9*9*8*7*6*5*4;
        nums[8]= nums[7]+9*9*8*7*6*5*4*3;
        nums[9]= nums[8]+9*9*8*7*6*5*4*3*2;
        return nums[n];
    }
};