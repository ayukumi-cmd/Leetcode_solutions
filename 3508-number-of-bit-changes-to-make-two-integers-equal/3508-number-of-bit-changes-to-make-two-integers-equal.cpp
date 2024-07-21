class Solution {
public:
    int minChanges(int n, int k) {
    
        if (n < k) {
            return -1;
        }
        

        if (n == k) {
            return 0;
        }

        int cnt = 0;

        for (int i = 0; i <=31; i++) {
 
            bool nBit = (n & (1 << i));
            bool kBit = (k & (1 << i));

            cout<<nBit<<" "<<kBit<<endl;

            if (nBit==1 && kBit==0) {
                cnt++;
            }
            else if(nBit==0 and kBit==1){
                return -1;
            }
        }

        return cnt;
    }
};
