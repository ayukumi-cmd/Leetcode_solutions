
class Solution {
    unordered_set<int> set;
    int memo[3002][3002];
    int n, m;
    int rec(string &source, string &pattern, int i, int j, vector<int> &targetIndices){
	
        if(memo[i][j] != -1) 
            return memo[i][j];

        if(j == m){
            auto it = lower_bound(targetIndices.begin(), targetIndices.end(), i);
            if(it != targetIndices.end()){
                int index = it - targetIndices.begin();
                return targetIndices.size() - index;
            }
            return 0;
        }
        
	
        if(i == n)
            return -1e9;

        int ans = rec(source, pattern, i + 1, j, targetIndices);

        if(source[i] == pattern[j])
            ans = max(ans, rec(source, pattern, i + 1, j + 1, targetIndices));

        if(set.find(i) != set.end()){
            int temp = rec(source, pattern, i + 1, j, targetIndices);
            if(temp != -1e9)
                ans = max(ans, 1 + temp);
        }
        return  memo[i][j] = ans;
    }
public:
    int maxRemovals(string &source, string &pattern, vector<int>& targetIndices){
        n = source.size(), m = pattern.size();
        for(int &i: targetIndices)
            set.insert(i);
        
        memset(memo, -1, sizeof(memo));
        return rec(source, pattern, 0, 0, targetIndices);
    }
};