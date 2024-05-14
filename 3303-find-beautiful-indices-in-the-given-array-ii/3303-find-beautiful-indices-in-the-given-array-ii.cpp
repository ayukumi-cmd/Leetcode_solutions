class Solution {
public:
    vector<int> kmp(string str){
        vector<int> lps(str.size(), 0);

        for(int i = 1; i < str.size(); ++i){
            int prevIndex = lps[i - 1];
            while(prevIndex > 0 && str[i] != str[prevIndex]){
                prevIndex = lps[prevIndex - 1];
            }

            lps[i] = prevIndex + (str[i] == str[prevIndex] ? 1 : 0);
        }

        return lps;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string match1 = a + '#' + s;
        string match2 = b + '#' + s;

        vector<int> lps1 = kmp(match1);
        vector<int> lps2 = kmp(match2);

        vector<int> freqa;
        for(int i = a.size() + 1; i < lps1.size(); ++i){
            if(lps1[i] == a.size()) freqa.push_back(i - a.size() - a.size());
        }

        vector<int> freqb;
        for(int i = b.size() + 1; i < lps2.size(); ++i){
            if(lps2[i] == b.size()) freqb.push_back(i - b.size() - b.size());
        }

        vector<int> ans;
        for(int i = 0; i < freqa.size(); ++i){
            auto j = lower_bound(freqb.begin(), freqb.end(), freqa[i]) - freqb.begin();
            if(j != freqb.size() && abs(freqa[i] - freqb[j]) <= k) {
                ans.push_back(freqa[i]);
                continue;
            }
            if(j != 0 && abs(freqa[i] - freqb[j - 1]) <= k) {
                ans.push_back(freqa[i]);
            }
        }

        return ans;
    }
};