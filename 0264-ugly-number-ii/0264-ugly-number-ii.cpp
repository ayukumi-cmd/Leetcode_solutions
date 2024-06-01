class Solution {
public:
    // unordered_map<int, bool>mp;
    // bool solve(int n){
    //     if(n==1){return true;}
    //     if(n==0){return false;}
    //     if(mp.find(n)!=mp.end()){
    //         return mp[n];
    //     }
    //     bool ans=false;
    //     if(n%2==0){
    //     ans|=solve(n/2);
    //     }
    //     if(n%3==0){
    //         ans|=solve(n/3);
    //     }
    //     if(n%5==0){
    //         ans|=solve(n/5);
    //     }
    //     mp.insert({n, ans});
    //     return ans;
    // }
    // int nthUglyNumber(int n) {
    //     mp.clear();
    //     int cnt=0;
    //     int ans=0;
    //     int i=1;
    //     while(true){
    //         if(solve(i)){
    //             cnt++;
    //             if(cnt==n){
    //             ans=i; break;
    //             }
    //         }
    //         i++;
    //     }
    //     return ans;
    // }


    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;

        for (int i = 1; i < n; i++) {
            int next_ugly = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            ugly[i] = next_ugly;

            if (next_ugly == ugly[i2] * 2) i2++;
            if (next_ugly == ugly[i3] * 3) i3++;
            if (next_ugly == ugly[i5] * 5) i5++;
        }

        return ugly[n - 1];
    }
};
