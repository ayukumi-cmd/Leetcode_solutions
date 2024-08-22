class Solution {
public:

    int st_in(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans += (1 << (n - i - 1));  
            }
        }
        return ans;
    }

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int, vector<int>> mp;
        int n = s.length();

        for (int i = 0; i < n; i++) {
          
            
            string temp;
            for (int j = i; j < min(30 + i, n); j++) {
                temp += s[j];  
                if((s[i]=='0' and temp.size()==1)||(s[i]!='0')){
                int ans = st_in(temp);
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                if (mp.find(ans) == mp.end()) {
                    mp.insert({ans, v});
                }
            }
          }
        }

        vector<vector<int>> result;
        for (auto it : queries) {
            int x = it[0];
            int y = it[1];
            int xori = x ^ y;
            
            if (mp.find(xori) != mp.end()) {
                result.push_back(mp[xori]);
            } else {
                result.push_back({-1, -1});
            }
        }
        return result;
    }
};
