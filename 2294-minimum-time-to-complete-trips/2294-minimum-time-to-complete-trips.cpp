class Solution {
public:
     int bs(vector<int>&time, long long  x, int total){
        long long  n= time.size(); 
         long long sum=0;
        for(int i=0; i<n; i++){
         sum+=(x/time[i]);
        }

        return sum>=total;
     }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long  prod=1; long long  n= time.size();

        long long  sum=0; 

        for(int i=0; i<n; i++){
            sum+=time[i];
        }
        long long prod_sum=0;

        for(int i=0; i<n; i++){
          prod_sum+=sum/time[i];
        }
         long long  x=totalTrips/prod_sum;
         long long  y=totalTrips%prod_sum;
         if(y){x++;}
         long long  l= sum*x;

        sort(time.begin(), time.end());
         long long  ans=0;
        long long s= 1; 
        while(s<=l){
            long long mid=s+(l-s)/2; 
            bool f= bs(time, mid, totalTrips);
            if(f){
                ans= mid;
                l= mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
        
    }
};