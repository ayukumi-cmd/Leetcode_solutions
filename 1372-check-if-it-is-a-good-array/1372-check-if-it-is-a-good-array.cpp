class Solution {
public:
    bool isGoodArray(vector<int>& nums) {

     // diophantine equation 
     // ax+by=c is solvable if and only if c is divisible  gcd(a, b);
     // so if any subset generate gcd equal to 1 then it is possible return true;

     // now how will you find which subset generate gcd =1 
     //simple take gcd of elements if it results in 1 then obv there will be atleast 1 subset which has gcd 1 and that's why gcd of all elements is 1

     int gcdd=nums[0];
     for(int i=0; i<nums.size(); i++){
       gcdd=__gcd(gcdd, nums[i]);
     }

     return gcdd==1;

    }
};