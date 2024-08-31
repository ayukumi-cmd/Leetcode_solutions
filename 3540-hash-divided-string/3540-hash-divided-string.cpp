class Solution {
public:
    string stringHash(string s, int k) {
      
        int sum=0; 
        string ans;
        for(int i=0; i<s.size(); i++){
            sum+=(s[i]-'a');

            if((i+1)%k==0){
              char l=((sum%26)+'a'); 
              ans+=l;
              sum=0;
            }
        }
        return ans;
    }
};