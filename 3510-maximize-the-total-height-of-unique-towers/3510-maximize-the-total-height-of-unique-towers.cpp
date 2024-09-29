#define ll long long 
class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
       sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
       ll sum=maximumHeight[0];



       bool f= false;
       for(int i=1; i<maximumHeight.size(); i++){
        ll x=min(maximumHeight[i], maximumHeight[i-1]-1);
        if(x==0){f=true; break;}
        maximumHeight[i]= x; 
        sum+=x;
       } 


       
       if(f){return -1;}
       return sum;
    }
};