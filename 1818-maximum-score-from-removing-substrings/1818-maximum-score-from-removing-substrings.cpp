class Solution {
public:
    pair<string, int> ab(string &s, int x){
        stack<char>st;
        int ans=0; int n= s.length();
        for(int i=0; i<n; i++){
            if(st.empty()|| st.top()!='a'||s[i]!='b'){
                st.push(s[i]);
            }
            else{
                ans+=x;
                st.pop();
            }
        }

        string ret;
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }

        reverse(ret.begin(), ret.end());
        return make_pair(ret, ans);
    }      
    pair<string, int> ba(string &s, int x){
        stack<char>st;
        int ans=0;int n= s.length();
        for(int i=0; i<n; i++){
            if(st.empty()|| st.top()!='b'||s[i]!='a'){
                st.push(s[i]);
            }
            else{
                ans+=x;
                st.pop();
            }
        }

        string ret;
        while(!st.empty()){
            ret+=st.top();
            st.pop();
        }

        reverse(ret.begin(), ret.end());
        return make_pair(ret, ans);
    }      
    
    int maximumGain(string s, int x, int y) {
        int n= s.length();
        int ans=0;
        if(x>y){
            pair it=ab(s, x);
            string t= it.first;
            ans+=it.second;
            pair tt=ba(t, y);
            ans+=tt.second;
        }

        else{
            pair it=ba(s, y);
            string t= it.first;
            ans+=it.second;
            pair tt=ab(t, x);
            ans+=tt.second;          
        }

        return ans;
    }
};