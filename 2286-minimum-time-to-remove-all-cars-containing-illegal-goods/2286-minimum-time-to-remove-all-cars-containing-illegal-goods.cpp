class Solution {
public:
    int minimumTime(string s) {
    if ( s.size() == 1 and s.at(0) == '1') return 1;
    if ( s.size() == 1 and s.at(0) == '0') return 0;
    
    vector<int> a( s.size() , 0);
    
    for ( auto i : s){
        if ( i == '0') a.push_back(-1);
        else a.push_back(1);
    }
    
    int mn = INT_MAX;
    int sum = 0;
    
    for( auto i : a){
        sum += i;
        
        mn = min ( mn , sum);
        if ( sum > 0) sum = 0;
    }
    
    return s.size() + mn;
}
};