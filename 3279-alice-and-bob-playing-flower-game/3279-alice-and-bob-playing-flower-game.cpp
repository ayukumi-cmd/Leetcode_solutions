class Solution {
public:
    long long flowerGame(int n, int m) {
    long long  odd1=(n%2==0)?n/2:((n/2)+1);
    long long  even1=n/2;
    long long  odd2=(m%2==0)?m/2:((m/2)+1);
    long long  even2=m/2;
    long long  ans= (odd1*even2)+(odd2*even1);
    return  ans;

    }
};