class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ret, empty;
        
        int n = colsum.size();
        ret.resize(2);
        ret[0].resize(n);
        ret[1].resize(n);
        for( int i=0; i<n; i++ )
        {
            if ( colsum[i] == 2 )
            {
                ret[0][i] = 1;
                ret[1][i] = 1;
                upper--;
                lower--;
            }
            if ( upper < 0 || lower < 0 )
                return empty;
        }
        
        for( int i=0; i<n; i++ )
        {
            if ( colsum[i] == 1 )
            {
                if ( upper > 0 )
                {
                    ret[0][i] = 1;
                    upper--;
                }
                else
                {
                    ret[1][i] = 1;
                    lower --;
                }
            }
            if ( upper < 0 || lower < 0 )
                return empty;
        }
        
        if ( upper!=0 || lower!=0 )
            return empty;
        else
            return ret;
    }
};