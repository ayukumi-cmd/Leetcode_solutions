class Solution {
public:
    int maxOperations(string s) {
        int n= s.length();

        int cnt=0;
        int cnt0=0; int cnt1=0;
        bool f0=false;

        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                if(f0==true){
                    cnt+=(cnt1);
                    cnt0=0; f0=false;
                }
               cnt1++;
            }
                else if(s[i]=='0'){
                    cnt0++;
                    f0=true;
                }
        }

        if(f0==true){
            cnt+=cnt1;
        }
        return  cnt;
    }
};