class Solution {
public:
    int passThePillow(int n, int time) {
      int x=time/(n-1); 
      if(x%2==0){return 1+time%(n-1);}
      else{return n-time%(n-1) ;}
    }
};