class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt=0;
        for(int i=0; i<=min(limit, n); i++){
                for(int j=0; j<=min(limit, n); j++){
                   for(int k=0; k<=min(limit, n); k++){
                    if(k+j+i==n){cnt++;}
                   }
            }
        }
        return cnt;

    }
};