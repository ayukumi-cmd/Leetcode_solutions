class Solution {
    public int singleNumber(int[] nums) {
        int len= nums.length;

         int xorr=0; 
         for(int i=0;i<len; i++){
            xorr^=nums[i]; 
         }
         return xorr;
    }
}