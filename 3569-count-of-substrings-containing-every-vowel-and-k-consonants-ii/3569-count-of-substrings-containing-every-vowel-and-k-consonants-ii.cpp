class Solution {
public:
    long long countOfSub(string word,int k){
        int n=word.length();
        long long finalCnt=0;
        long long i=0,j=0,cntConsonants=0;
        unordered_map<char,long long>mp;
        while(j<n){
            char ch=word[j];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u'){
                mp[ch]++;
            }
            else{
                cntConsonants++;
            }
            if(mp.size()<5 || cntConsonants<k){
                j++;
            }
            else if(mp.size()==5 && cntConsonants>=k){
                while(i<j && mp.size()==5 && cntConsonants>=k){
                    finalCnt+=n-j;
                    char chBack=word[i];
                    if(chBack=='a' || chBack=='e' || chBack=='i' || chBack=='o'|| chBack=='u'){
                        mp[chBack]--;
                        if(mp[chBack]<=0)mp.erase(chBack);
                    }
                    else{
                        cntConsonants--;
                    }
                    i++;
                }
                j++;
            }
            else j++;
        }
        return finalCnt;
    }
    long long countOfSubstrings(string word, int k) {

       return countOfSub(word,k)-countOfSub(word,k+1);
    }
};