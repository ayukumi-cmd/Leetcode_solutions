class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
       int n= nums.size();
       vector<int>mini(n , 0);
       vector<int>maxi(n ,0);
       int mn=INT_MAX;
       int mx=INT_MIN;
       
       for(int i=0; i<n; i++){
        mx= max(mx, nums[i]);
        mn= min(mn, nums[n-1-i]);
        mini[n-i-1]=mn; 
        maxi[i]=mx;
       }
    
       int cnt=0;
       for(int i=0; i<n-1; i++){
        cnt++;
        if(maxi[i]<=mini[i+1]){break;}
        
       }
        return cnt==0?1:cnt;
    }
};