class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int i=0; int j=0;  int n= nums.size();
        int count=0;
        int ans=0;
        while(j<n){
            if(nums[j]=='T'){
                count++;
            }
            while(count>k){
                if(nums[i]=='T'){count--;}
                i++;
            }
            ans= max(ans, j-i+1);
            j++;
        }
        j=0; i=0;count=0;
        while(j<n){
            if(nums[j]=='F'){
                count++;
            }
            while(count>k){
                if(nums[i]=='F'){count--;}
                i++;
            }
            ans= max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

