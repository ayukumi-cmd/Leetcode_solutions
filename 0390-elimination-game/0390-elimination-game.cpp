class Solution {
public:
    int lastRemaining(int n) {
        if(n==1){return 1;}
        if(n==2|| n==3){return 2; }

        return 2*(n/2-lastRemaining(n/2)+1);
    }
};