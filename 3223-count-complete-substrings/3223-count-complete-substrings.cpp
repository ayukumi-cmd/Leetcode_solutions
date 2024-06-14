class Solution {
    public:
        int countCompleteSubstrings(string word, int k) {
            int n = word.size();
            vector<vector<int>> freqs(n+1, vector<int>(26, 0));
            for(int i = 0; i < n; i++) {
                freqs[i+1] = freqs[i];
                freqs[i+1][word[i] - 'a']++;
            }
            int l = 0;
            int res = 0;
            for(int i = 0; i < n; i++) {
                if(i >= 1 && abs(word[i] - word[i-1]) > 2) {
                    l = i;
                }
                for(int c = 1; c <= 26; c++) {
                    int len = c * k;
                    int start = i - len + 1;
                    if(start < l) break;
                    bool f = true; 
                    for(int j = 0; j < 26; j++) {
                        int freq = freqs[i+1][j] - freqs[start][j];
                        if(freq != 0 && freq != k) {
                            f = false; 
                            break;
                        }
                    }
                    if(f) res++;
                }
            }
            return res;
        }
};

