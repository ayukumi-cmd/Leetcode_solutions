class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();

        int open=0; 
        int close=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='['){
                open++;
            }
            else if(s[i]==']') {
                close++;
            }

            if(open<close){
                ans++;
                open++; 
                close--;
            }
        }

        return ans;
    }
};
