class Solution {
public:
bool isPrime(int n)
{
   
    if (n <= 1)
        return false;


    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

    int nonSpecialCount(int l, int r) {
        int x=sqrt(l);
        int ans=0;
        while(x*x<=r){
            if(x*x>=l and x*x<=r and isPrime(x)){
                ans++;
            }
            x++;
        }
        return (r-l+1)-ans;
    }
};