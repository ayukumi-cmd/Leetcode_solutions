class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        for(int i = 0; i<word.size();i++) {
             int count = 1;
            while(word[i] == word[i+1] && count < 9) {
                count++;
                i++;
            }
            comp.push_back(count + '0');
            comp.push_back(word[i]);
        }
        return comp;
    }
};
