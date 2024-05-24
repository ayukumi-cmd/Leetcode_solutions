class Solution {
public:
    bool check(string &str1, string &str2){
        if(str1.length()>str2.length()){return false;}
        int i=0, j=0;
        while(i<str1.length()){
            if(str1[i]!=str2[j]){return false;}
            i++; j++;
        }
        i=str1.length()-1; j=str2.length()-1;
        while(i<str1.length()){
            if(str1[i]!=str2[j]){return false;}
            i--; j--;
        } 
        return true;  
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                count+=(check(words[i], words[j])==true)?1:0;
            }
        }
        return count;
    }
};