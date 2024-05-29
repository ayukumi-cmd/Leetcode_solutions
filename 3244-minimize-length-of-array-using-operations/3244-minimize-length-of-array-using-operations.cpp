class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mini =*min_element(nums.begin(), nums.end());
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==mini){
            count++;
            }
            else if(nums[i]%mini!=0){
                return 1; // always possible to make 1 length because if there multiple occurrance of same number then also we can make that occurance remove;
            }
        }
        if(count==1){
            return 1;
        }
        if(count%2){return 1+count/2;}
        else return count/2;
    }
};