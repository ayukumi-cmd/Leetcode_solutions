class Solution {
public:
    int countSubstrings(string s, string t) {
        int n= s.size();
        int m= t.size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                int x= i;
                int y= j;
                int diff=0;

                while(x<s.size() and y<t.size()){
                    if(s[x]!=t[y]){diff++;}
                    if(diff==1){ans++;}
                 
                    if(diff>1){break;}
                    x++;
                    y++;
                }
            }
        }
        return ans;
    }
};