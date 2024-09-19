class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n=s.length(); int m=target.length(); 
        if(n!=m){return false;}

        bool issame= false;
        int cnt1=0; int cnt0=0;
        for(int i=0; i<n; i++){
         if(s[i]==target[i] and s[i]=='1'){issame=true;}
         else if(s[i]!=target[i] and s[i]=='1'){cnt1++;}
         else if(s[i]!=target[i] and s[i]=='0'){cnt0++;}
        }
        if((cnt1==0 and cnt0==0)||issame){return true;}
        if(cnt1>0 and cnt0>0){return true; }
        
        return false;
    }
};