class Solution {
public:
    int findComplement(int num) {
        int x=32-(__builtin_clz(num));
        int ans=0;
        for(int i=0; i<x; i++){
            int y= (1<<i)&(num);
            if(y==0){
             ans+=pow(2, i);
            }
        }
        return ans;

    }
};