class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n= s.length();
        int s1=0, s0=0; 
        int j=0; int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){s0++;}
            else if(s[i]=='1'){s1++;}
            
            while(s0>k and s1>k){
            if(s[j]=='0'){s0--;}
            else if(s[j]=='1'){s1--;}
            j++;
            }

            if(s0<=k or s1<=k ){
                int len= (i-j+1);
                ans+=len;
            }
        }
        return ans;
    }
};