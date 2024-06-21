#define ll long long 
class Solution {
public:
    ll solve(vector<int>&nums1, vector<int>&nums2, ll x, ll y){
        ll n= nums1.size();
        ll cnt=0;
        for(ll i=0; i<n; i++){
            if(nums1[i]<=x and nums2[i]<=y){
                continue;
            }
            else if(nums1[i]<=y and nums2[i]<=x){
                cnt++;
            }
            else return -1;
        }
        return cnt;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       ll n=nums1.size();
       ll x=nums1[n-1];
       ll y=nums2[n-1];

       
       ll ans1=solve(nums1, nums2, x, y);
       swap(nums1[n-1], nums2[n-1]);
       ll ans2=solve(nums1, nums2, y, x); 
        
       if(ans1==-1 and ans2==-1){return -1;}

       else if(ans1==-1){return ans2+1;}
       else if(ans2==-1){return ans1;}

       else {
        return min(ans1,  ans2+1);
       }

    }
};