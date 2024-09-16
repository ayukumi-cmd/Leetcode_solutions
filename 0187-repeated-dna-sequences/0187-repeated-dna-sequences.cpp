#define ll long long 
int mod= 1e9+7;
class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int len = s.size();
        
        if(len <= 10) return result;
        
        unordered_map<string,int>mp;
        
        for(int i = 0; i <= len - 10; i++){
            string subseq = s.substr(i, 10);
            
            
                mp[subseq]++;
            
        }
        
        for(auto it : mp) {
           if(it.second>=2){result.push_back(it.first);}
        }
        
        return result;
    }

};