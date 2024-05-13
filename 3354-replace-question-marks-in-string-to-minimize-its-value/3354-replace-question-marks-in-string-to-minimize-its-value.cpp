class Solution {
public:
    string minimizeStringValue(string s) {
        string ans = "";
        
        unordered_map<char, int> freq;
        multiset<pair<int, char>> ms;
        
        for(auto c : s){
            freq[c]++;
        }
        
        for(char c='a'; c<='z'; c++){
            ms.insert({freq[c], c});
        }
        
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s[i];
            if(c == '?'){
                pair<int, char> p = *ms.begin();
                ms.erase(p);
                
                freq[p.second]++;
                ans+=(p.second);
                ms.insert({freq[p.second], p.second});
            }else{
                ans+=(c);
            }
        }
        
        string fans = "", temp = "";
        for(int i=0; i<n; i++){
            if(s[i] == '?')
                temp.push_back(ans[i]);
        }
        
        sort(temp.rbegin(), temp.rend());
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                fans.push_back(temp.back());
                temp.pop_back();
            }else{
                fans.push_back(ans[i]);
            }
        }
        return fans;
    }
};