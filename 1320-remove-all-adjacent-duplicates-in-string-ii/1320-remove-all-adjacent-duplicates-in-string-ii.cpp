class Solution {
public:
    string removeDuplicates(string s, int k) {
    stack<pair<char, int>>st;

    st.push({s[0], 1});

    for(int i=1; i<s.size(); i++){
      
      if(!st.empty() and s[i]==st.top().first  ){
        int count= st.top().second;
        st.pop();
        st.push({s[i], count+1});
      }
      else {
        st.push({s[i], 1});
      }
      if(st.top().second==k){
        st.pop();
      }
    }
    
    string ans; 
    while(!st.empty()){

        int count = st.top().second; 
        while(count--){
            ans+=st.top().first;
        }
       
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;


    }
};