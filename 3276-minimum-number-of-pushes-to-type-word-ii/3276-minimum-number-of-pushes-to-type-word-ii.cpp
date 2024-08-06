using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> v(26, 0);
        for (int i = 0; i < n; i++) {
            v[word[i] - 'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());

        int cnt = 1;
        int ans = 0;
        for (auto i : v) {
            if (cnt <= 8) {
                ans += i;
            } else if (cnt > 8 && cnt <= 16) {
                ans += i * 2;
            } else if (cnt > 16 && cnt <= 24) {
                ans += i * 3;
            } else {
                ans += i * 4;
            }
            if (i != 0) {
                cnt++;
            }
        }
        return ans;
    }
};
