class Solution {
    long long dp[102][102][102][3];
    int n, m;
    long long solve(int i, int a, int b, int cnt, vector<vector<pair<int, int> >>& board){
        if(cnt == 3) return 0;
        if(i >= n) return -1e16;

        if(dp[i][a][b][cnt] != -1) return dp[i][a][b][cnt];

        long long ans = -1e16;
        for(auto it: board[i]){
            int val = it.first, k = it.second;
            if(k != a && k != b){
                if(a == 101) ans = max(ans, solve(i+1, k, b, cnt+1, board)+val);
                else if(b == 101) ans = max(ans, solve(i+1, a, k, cnt+1, board)+val);
                else ans = max(ans, solve(i+1, a, b, cnt+1, board)+val);
            }
        }
        ans = max(ans, solve(i+1, a, b, cnt, board));

        return dp[i][a][b][cnt] = ans;
    }
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();

        vector<vector<pair<int, int> >> new_board(n);
        for(int i = 0; i < n; i++){
            vector<pair<int, int> > v;
            for(int j = 0; j < m; j++){
                v.push_back({board[i][j], j});
            }
            sort(v.begin(), v.end());
            for(int j = 0; j < 3; j++){
                new_board[i].push_back({v[m-1-j].first, v[m-1-j].second});
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 101, 101, 0, new_board);
    }
};