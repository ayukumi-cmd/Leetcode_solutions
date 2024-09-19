#define ll long long
class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<ll>min_op(32, 0);
        min_op[0]=1; 

        for(int i=1; i<32; i++){
            min_op[i]=2*min_op[i-1]+1;
        }
       ll sign =1; ll ans=0;
        for(int i=0; i<32; i++){
            bool bit = (n>>i)&1;
            if(bit==1){
                ans=ans+(sign*min_op[i]);
                sign =(-1)*sign;
            }
        }
        return (-1)*(sign)*ans;
    }
};