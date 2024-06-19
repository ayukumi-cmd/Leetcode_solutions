
#define ll long long
class Solution {
public:
    bool solve( vector<ll>&diff, ll mid, ll p){
        ll count1=0;

        for(ll i=0; i<diff.size(); i++){
            if(diff[i]<=mid){count1++; i++;}
            else {continue;}
        }
        ll count2=0;
        for(ll i=1; i<diff.size(); i++){
            if(diff[i]<=mid){count2++; i++;}
            else {continue;}
        }

        ll county=max(count1, count2);

        return county>=p;

    }
  
    int minimizeMax(vector<int>& nums, int p) {
     ll n=nums.size();
     if(p==0){return 0;}
     sort(nums.begin(), nums.end());

     vector<ll>diff;
     ll start=LLONG_MAX;
     for(int i=0; i<n-1; i++){
        diff.push_back(nums[i+1]-nums[i]);
        start=min(start, static_cast<ll>(nums[i+1]-nums[i]));
     }


     ll end= nums[n-1]-nums[0];

     ll ans=INT_MAX;
     while(start<=end){
        ll mid=start+(end-start)/2;

        if(solve( diff, mid, p)){
         ans=mid;
         end= mid-1;
        }
        else {
            start= mid+1;
        }
     }
     return ans;

       

    }
};