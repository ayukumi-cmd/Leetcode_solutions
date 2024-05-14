class Solution {
public:
    bool isSubstringPresent(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int l = s.length();
        int i=0;
        while(i<l-1)
        {
            if(rev.find(s.substr(i,2))!=string::npos)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};