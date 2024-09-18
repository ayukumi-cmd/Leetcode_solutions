class Solution {
public:
    static bool cmp(string &a, string &b){
     return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>st; 

        for(auto it:nums){
            st.push_back(to_string(it));
        }

        sort(st.begin(), st.end(), cmp);
        string result;
        if(st[0]=="0"){return "0";}
        for (auto &s : st) {
            result += s;
        }

        return result;

    }
};