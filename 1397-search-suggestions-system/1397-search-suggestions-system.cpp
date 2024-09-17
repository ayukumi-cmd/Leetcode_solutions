class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string w) {
        sort(p.begin(), p.end());
        int l = 0, r = p.size()-1;
        vector<vector<string>> res(w.size());
        for(int i=0; i<w.size(); i++){
            while(l<=r && (p[l].size()<i+1 || p[l][i]<w[i])) l++;
            while(l<=r && (p[r].size()<i+1 || p[r][i]>w[i])) r--;
            for(int j=l; j<=r && j<l+3; j++){
                res[i].push_back(p[j]);
            }
        }
        return res;
    }
};