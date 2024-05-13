class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans(n, "");
        
        unordered_map<int, unordered_set<string>> mp;
        for(int k=0; k<n; k++){
            string s = arr[k];
            int sz = s.length();
            for(int i=0; i<sz; i++){
                for(int j=i; j<sz; j++){
                    string temp = s.substr(i, j-i+1);
                    mp[k].insert(temp);
                }
            }
        }
        
        for(int k=0; k<n ;k++){
            
            string minString = "", s = arr[k];
            int curLen = 0, minLen = INT_MAX, sz = s.length();
            
            for(auto temp : mp[k]){
                bool flag = true;
                for(int j=0; j<n; j++){
                    if(k == j) continue;
                    if(mp[j].contains(temp)){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(temp.length() < minLen){
                        minLen = temp.length();
                        minString = temp;
                    }else if(temp.length() == minLen && temp < minString){
                        minString = temp;
                    }
                }
            }
            
            ans[k] = minString;
        }
        
        return ans;
    }
};