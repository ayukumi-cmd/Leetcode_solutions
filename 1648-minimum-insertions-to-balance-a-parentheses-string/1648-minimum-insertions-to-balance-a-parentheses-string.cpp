class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (i < n - 1 && s[i + 1] == ')') {
                    if (st.empty()) {
                        ans++;
                    } else {
                        st.pop();
                    }
                    i++;
                } else {
                    if (st.empty()) {
                        ans += 2;
                    } else {
                        st.pop();
                        ans++;
                    }
                }
            }
        }
        return ans + 2 * st.size();
    }
};
