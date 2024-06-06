#define mod 1000000007
class Solution {
public:
//     long long  solve(vector<int>&arr){
//     int n=arr.size();
//         vector<long long>right(n, 0);
//         stack<pair<int, long long>> sRight;
//         for(int i=n-1;i>=0;i--){
//             int cnt = 1;
//             while(!sRight.empty() && sRight.top().first == arr[i]) {
//                 cnt += sRight.top().second;
//                 sRight.pop();
//             }
//             sRight.push({arr[i], cnt});
//             right[i] = cnt;
//         }
//         long long ans=0;
//         int  i=0;
//         while(i<n){
//         ans+=right[i];
//         i=i+right[i];
//         }
// return ans;
//     }
    int countHomogenous(string s) {
      int n= s.length();   long long count =1;  long long  curr=1;
      for(int i=1; i<n; i++){
      if(s[i]==s[i-1]){
        curr++;
        count=(count%mod+curr%mod)%mod;
      }
      else {
        count++;
        count%mod;
        curr=1;
      }
      }
       return count%mod; 
    }
};