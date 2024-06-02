class Solution {
public:
static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first== b.first) return a.second < b.second;
    return a.first > b.first;
}

string clearStars(string s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
    string ans = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != '*') {
            pq.push({s[i], i});
        } else {
            s[pq.top().second] = '*';
            pq.pop();
        }
    }
    for(auto c: s)
        if(c != '*') ans += c;
    return ans;
}

};