class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flip=0;
        queue<int>q;
        for(int i=0; i<n;i++){
            if(!q.empty() and q.front()<i){
                q.pop();
            }
            if(q.size()%2==nums[i]){
               if(i+k-1>=n){
                return -1;
               }
               flip++;
               q.push(i+k-1);

            }
        }
        return flip;

    }
};