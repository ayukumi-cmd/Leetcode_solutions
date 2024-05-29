class Solution {
public:
int numSteps(string &s) {
    int res = 0, carry = 0;
    for (auto i = s.size() - 1; i > 0; --i) {
        
        if (s[i] - '0' + carry == 1) {
            carry = 1;
            res+=2; // one operation for adding and when it becomes even 1 operation for dividing by 2
        }
        else if(s[i]-'0'+carry==0){
          
              res+=1; // only one operation for dividing by 2;
        }

        else if(s[i]-'0'+carry==2){
            res+=1;
        }
    }
    return res + carry;
}
    
};
