class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n= a.size(); 
        if(n<3){return 0;}
        int ans=0;
        int diff=a[1]-a[0];
        int cnt=1; 
        for(int i=1; i<n; i++){
           if((a[i]-a[i-1])==diff){
              cnt++;
           }
           else {
            ans+=((cnt-1)*(cnt-2))/2; 
            cnt=2; diff=a[i]-a[i-1];
           }
        }
        ans+=((cnt-1)*(cnt-2))/2;
        return ans; 
    }
};