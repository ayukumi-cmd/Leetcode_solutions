class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1, r = k+1;
        vector<int> ans;
        int cnt=0;
        while (cnt!=k+1) {
            ans.push_back(l++);
            cnt++;
            if(cnt<k+1){ ans.push_back(r--);}
            else {break;}
            cnt++;
        }
        for (int i = k+2; i <= n; i++)
            ans.push_back(i);
        return ans;
    }
};