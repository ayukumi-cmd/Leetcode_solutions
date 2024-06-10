#define ll long long 
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
    ll n=word.size();ll count=0;
    word+='#';
    for(ll i=1; i<n; i++){
    if(word[i]==word[i-1]|| abs(word[i]-word[i-1])==1){
       for(ll j=0; j<26; j++){
        if((j+'a'!=word[i] )and (j+'a'!=word[i-1]) and (j+'a'!=word[i+1]) and (j+'a'!=word[i+1]+1) and (j+'a'!=word[i+1]-1) and (j+'a'!=word[i-1]+1) and (j+'a'!=word[i-1]+1)){
         word[i]=j+'a';
         count++;
         break;
        }
       }
    }
    }
    return count;

    }
};