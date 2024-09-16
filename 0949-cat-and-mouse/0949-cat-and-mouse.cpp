#define ll long long 
class Solution {
public:
    vector<vector<vector<ll>>> dp;

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        dp.resize(5 * n+3, vector<vector<ll>>(n, vector<ll>(n, -1)));
        return search(graph, 0, 1, 2);
    }

    int search(vector<vector<int>>& graph, ll t, ll x, ll y) {
        if (t ==graph.size() * 5) return 0;
        if (x == y) return dp[t][x][y] = 2;
        if (x == 0) return dp[t][x][y] = 1;
        if (dp[t][x][y] != -1) return dp[t][x][y];
        
        ll who = t % 2;
        bool flag;

        if (who == 0) { 
            flag = true;
            for (int i = 0; i < graph[x].size(); i++) {
                ll nxt = search(graph, t + 1, graph[x][i], y);
                if (nxt == 1) return dp[t][x][y] = 1;
                else if (nxt != 2) flag = false;
            }
            if (flag) return dp[t][x][y] = 2;
            else return dp[t][x][y] = 0;
        } else { // Cat's turn
            flag = true;
            for (int i = 0; i < graph[y].size(); i++) {
                if (graph[y][i] != 0) {
                    ll nxt = search(graph, t + 1, x, graph[y][i]);
                    if (nxt == 2) return dp[t][x][y] = 2;
                    else if (nxt != 1) flag = false;
                }
            }
            if (flag) return dp[t][x][y] = 1;
            else return dp[t][x][y] = 0;
        }
    }
};
