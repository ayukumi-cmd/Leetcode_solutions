class Solution {
public:
    string inv(string s){
        string ans; 
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                ans+='0';
            }
            else {
                ans+='1';
            }
        }
        return ans;
    }
    string solve(int i){
        if(i==1){return "0";}

        string x= solve(i-1); 
        string y= inv(x);
        reverse(y.begin(), y.end());
        string ans= x+"1"+ y;
        return ans;
    }
    char findKthBit(int n, int k) {
        string res= solve(n);
        return res[k-1];
    }
};