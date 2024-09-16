#define ll long long 
int mod= 1e9+7;
class Solution {
public:
//    int  rabin(string hay, string needle){
//         int n= hay.size(); 
//         int m= needle.size();
//         ll radix=26, max_weight= 1;
//         for(ll i=1; i<=m ;i++){
//             max_weight=(max_weight*radix)%mod;
//         }
//         ll hashneedle=hash(needle, radix, m);

//         for(ll i=0; i<=(n-m); i++){
//             if(i==0){itn hashhay= hash(hay, radix, m);}
//             else{
//                 hashhay=((hashhay*radix)%mod-((hay[i-1]-'a')*max_weight)%mod+(hay[i+m-1]-'a')+mod)%mod
//             }

//             if(hashhay==hashneedle){
//                 return i;
//             }
//         }
//         return -1;


//     }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int len = s.size();
        
        if(len <= 10) return result;
        
        unordered_set<string> seen;
        unordered_set<string> repeated;
        
        for(int i = 0; i <= len - 10; i++){
            string subseq = s.substr(i, 10);
            
            if(seen.find(subseq) != seen.end()) {
                repeated.insert(subseq);
            } else {
                seen.insert(subseq);
            }
        }
        
        for(const string& seq : repeated) {
            result.push_back(seq);
        }
        
        return result;
    }

};