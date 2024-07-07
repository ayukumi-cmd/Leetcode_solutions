class Solution {
public:
    
    int n;
    vector<vector<vector<int>>>t;
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person == 1) { //Alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { //Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
            
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        t.resize(2, vector<vector<int>>(n+1, vector<int>(200, -1)));
        
        
        return solveForAlice(piles, 1, 0, 1);
    }
};