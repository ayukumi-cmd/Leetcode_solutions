class Solution {
public:
    int m= 1000000;
    int minNumberOfFrogs(string s) {
         int c=0, r=0, o=0, a=0,k=0;
        for(int i=0; i<s.size(); i++){
          if(s[i]=='c'){ c++;}
          if(s[i]=='r'){ r++;}
          if(s[i]=='o'){ o++;}
          if(s[i]=='a'){ a++;}
          if(s[i]=='k'){ k++;}
          if(c<a||c<r||c<o||c<k){return -1;}
          if(r<o||r<a||r<k){return -1;}
          if(o<k||o<a){return -1;}
          if(a<k){return -1;}

        }
        int ans=INT_MIN;
        if(c!=r||c!=k||c!=o||c!=a){return -1;}
        c=0;r=0;o=0;a=0;k=0;

        for(int i=0; i<s.size(); i++){
         if(s[i]=='c'){ c++;}
         if(s[i]=='r'){ r++;}
         if(s[i]=='o'){ o++;}
         if(s[i]=='a'){ a++;}
         if(s[i]=='k'){ k++;}

         int mini= min({a,r,c, k, o});
         int maxi= max({a, r, c,k,o});

         if(mini>0){
            ans=max(ans, maxi);
            a-=mini; r-=mini; c-=mini;o-=mini; k-=mini;
         }
        }
         int mini= min({a,r,c, k, o});
         int maxi= max({a, r, c,k,o});

         if(mini>0){
            ans=max(ans, maxi);
            a-=mini; r-=mini; c-=mini;o-=mini; k-=mini;
         }
         return ans;


    }
};