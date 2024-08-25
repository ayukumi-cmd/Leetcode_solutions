class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st; 
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
           
           bool f=false;
            
            if(!st.empty() and st.top()==s[i]){
                st.pop(); f=true;
            }
           if(!f){st.push(s[i]);}
        }
        string ans;
        while(!st.empty()){
          ans+=st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};