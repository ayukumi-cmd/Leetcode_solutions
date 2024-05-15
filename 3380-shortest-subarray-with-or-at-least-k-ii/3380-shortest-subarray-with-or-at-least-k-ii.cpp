// class Solution {
// public:
//     int make_num(vector<int>v){
//         int x=0;
//         for(int i=0; i<32; i++){
//            if(v[i]>0){
//             x+=pow(2, i)*1;
//            }
//         }
//         return x;
//     }
//     int minimumSubarrayLength(vector<int>& nums, int u) {
//         int n= nums.size();
//         int i=0, j=0;
//         vector<int>v(32, 0);
//         int ans=INT_MAX;

//         while(j<n){
//         for(int k=0; k<32 ; k++){
//         v[k]+=(nums[j]&1);
//         nums[j]=nums[j]>>1;
//         }
//         int ory=make_num(v);
//         if(ory>=u and ory!=0){
//         ans=min(ans,j-1+1);
//         while(ory>=u and ory!=0 and i<j){
//         ans= min(ans, j-i+1);
//         for(int k=0; k<32 ; k++){
//         v[k]-=(nums[i]&1);
//         nums[i]=nums[i]>>1;
//         }
//         ory=make_num(v);
//         i++;
//         }

//         }
//         j++;

//         }
//         return ans;
//     }
// };



class Solution {
public:
    int make_num(const vector<int>& v) {
        int x = 0;
        for(int i = 0; i < 32; i++) {
            if(v[i] > 0) {
                x += pow(2, i);
            }
        }
        return x;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> v(32, 0);
        int ans = INT_MAX;

        while(j < n) {
            int temp= nums[j];
            for(int u = 0; u < 32; u++) {
                v[u] += (nums[j] & 1);
                nums[j] = nums[j] >> 1;
            }
            nums[j]=temp;
            int ory = make_num(v);
            
            if(ory >= k && ory != 0) {
                ans = min(ans, j - i + 1);
                while(ory >= k && ory != 0 && i <=j) {
                    ans = min(ans, j - i + 1);
                    for(int u = 0; u< 32; u++) {
                        v[u] -= (nums[i] & 1);
                        nums[i] = nums[i] >> 1;
                    }
                    ory = make_num(v);
                    i++;
                }
            }
            j++;
        }
        if( k==0) { ans=1;}
        return ans == INT_MAX ? -1 : ans;
    }
};



