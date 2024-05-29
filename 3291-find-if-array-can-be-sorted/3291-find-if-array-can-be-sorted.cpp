class Solution {
public:

   int count(int x){
    int cnt=0;
    while(x>0){
        x= x&(x-1);
        cnt++;
    }
    return cnt;
   }
    bool canSortArray(vector<int>& nums) {
       int n= nums.size();
       for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++){
        if(count(nums[j])==count(nums[i]) and nums[j]<nums[i]){
          swap(nums[i], nums[j]);
        }
        else if(count(nums[j])!=count(nums[i])){
            break;
        }
       }
       }
      if( is_sorted(nums.begin(), nums.end())==1){
        return true;
      }
      else return false;

       

    

      

    }
};