class Solution {
public:
    static int x;
    
    static bool cmp(const vector<int>& p1, const vector<int>& p2) {
        return p1[x] > p2[x];
    }

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        x = k;
        sort(score.begin(), score.end(), cmp); 
        return score;
    }
};

int Solution::x = 0;