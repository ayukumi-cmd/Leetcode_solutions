class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='a' ||s[i]=='e'|| s[i]=='i'||s[i]=='u'|| s[i]=='o'){
                cnt++;
            }
        }
        if(cnt==0){
            return false;
        }
        else return true;
    }
};