import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int x = target - nums[i]; 

            if (mp.containsKey(x)) {
                int [] v= new int[2];
                v[0]=mp.get(x); 
                v[1]=i;
                return v;
            }
            mp.put(nums[i], i);
        }
        return new int[] {};
    }
}
