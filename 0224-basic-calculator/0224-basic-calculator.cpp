class Solution {
public:
    int calculate(string s) {
        int result=0; 
        int num=0; 
        int n=s.size();
        int sign=1;stack<int>st;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                num= num*10 +(s[i]-'0');
            }
            else if(s[i]=='+'){
                result +=(num*sign);
                sign =1; 
                num=0; 
            }
            else if(s[i]=='-'){
                result+=(num*sign);
                sign=-1; 
                num=0;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0; sign=1; num=0;
            }
            else if(s[i]==')'){
                result+= num*sign; 
                num=0; 
                int latest_sign= st.top(); st.pop();
                int latest_result= st.top(); st.pop(); 
                result*=latest_sign;
                result+=latest_result;
            }
        }
        result+=(sign*num);
        return result;
    }
};

