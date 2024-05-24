class Solution {
public:
    set<string>make_hash(vector<int>&a){
        set<string>st;
        for(int i=0; i<a.size(); i++){
            string temp;
            string s=to_string(a[i]);
            for(int j=0; j<s.length(); j++){
             temp+=s[j];
             st.insert(temp);
            }

        }
        return st;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int ans= -1;
        set<string>st=make_hash(arr1);
        for(int i=0;i<m; i++){
            string s=to_string(arr2[i]);
            string temp;
            for(int j=0; j<s.length(); j++){
             temp+=s[j];
             if(st.find(temp)!=st.end()){ans= max(ans, j+1);}
            }
        }
        return ans==-1?0:ans;
    }
};