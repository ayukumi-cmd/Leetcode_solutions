class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();

        int open=0; int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='['){
                open++;
            }
            else if(s[i]==']') {
                open--;
            }

            if(open<0){
                ans++;
                open=1;
            }
        }

        return ans;
    }
};