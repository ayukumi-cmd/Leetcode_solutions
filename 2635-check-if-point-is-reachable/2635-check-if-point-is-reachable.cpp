class Solution {
public:
    bool isReachable(int targetX, int targetY) {

//  the main concept here -> if we will perform above mentioned operations  we can somehow relate the gcd of starting point to end point 
// If we move from (targetX, targetY) to the points (targetX, targetY - targetX) or (targetX – targetY, targetY), the GCD of the pair remains the same
// If we move from (targetX, targetY) to the points (2 * targetX, targetY) or (targetX, 2 * targetY), the GCD of the pair remains same or gets doubled.
// GCD of (1, 1) is 1. From here it can either remain same or get multiplied by 2 each time. Therefore, from the above observations, point (1, 1) can move to point (targetX, targetY) if and only if gcd of (targetX, targetY) is a power of 2.

   int  x= __gcd(targetX, targetY);
   // now check if x is power of 2 or not for that 
   return  (x & (x-1))==0;
  
    }
};
