class Solution {
public:
    int numberOfSpecialChars(string s) {
     vector<bool>l(26, false);
     vector<bool>u(26, false);
        for(auto i:s) {
        if(islower(i)){
            l[i-'a']=!u[i-'a'];
        }
        else{ u[i-'A']=true;  }
           
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(l[i] and u[i]){ans++;}
        }


        return ans;
    }
};

