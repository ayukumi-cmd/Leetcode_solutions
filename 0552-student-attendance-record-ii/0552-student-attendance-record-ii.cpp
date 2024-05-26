// class Solution {
// public:
//     vector<vector<vector<vector<int>>>>dp;
//     int MOD= 1000000007;
//     int solve(int con_L , int con_A, int curr, int k, int n){
//         if(k==n){
//            return (con_L < 3 && con_A < 2) ? 1 : 0;
//         }
//         if(con_L>=3 || con_A>=2){return 0;}
//         if(dp[con_L][con_A][k][curr]!=-1){return dp[con_L][con_A][k][curr]%MOD;}

//         int ans=0;
//         ans+=(solve(con_L+1, con_A, 1,k+1, n)%MOD);
//         ans+=(solve(0,con_A+1,2, k+1, n)%MOD);
//         ans= ans%MOD;
//         ans+=(solve(0, con_A , 0, k+1,n)%MOD);
//         dp[con_L][con_A][k][curr]=ans%MOD;
//         return dp[con_L][con_A][k][curr];

//     }
//     int checkRecord(int n) {
//         dp.assign(4,vector<vector<vector<int>>>(3, vector<vector<int>>(n+1, vector<int>(3, -1))));
//         int ans=0;
//         ans+=(solve(0, 0, 0, 1,n)%MOD);
//         ans+=(solve(1, 0, 1, 1,n)%MOD);
//         ans= ans%MOD;
//         ans+=(solve(0, 1, 2, 1,n)%MOD);
//         return ans;

//     }
// };


// class Solution {
// public:
//     vector<vector<vector<vector<int>>>> dp;
//     int MOD = 1000000007;

//     int solve(int consecutiveLates, int consecutiveAbsences, int currentState, int day, int n) {
//         if (day == n) {
//             return (consecutiveLates < 3 && consecutiveAbsences < 2) ? 1 : 0;
//         }
//         if (consecutiveLates >= 3 || consecutiveAbsences >= 2) {
//             return 0;
//         }
//         if (dp[consecutiveLates][consecutiveAbsences][day][currentState] != -1) {
//             return dp[consecutiveLates][consecutiveAbsences][day][currentState];
//         }

//         long long totalWays = 0;
//         totalWays += solve(consecutiveLates + 1, 0, 1, day + 1, n)%MOD;
//         totalWays += solve(0, consecutiveAbsences + 1, 2, day + 1, n)%MOD;
//         totalWays += solve(0, 0, 0, day + 1, n)%MOD;
//         totalWays %= MOD;

//         dp[consecutiveLates][consecutiveAbsences][day][currentState] = totalWays;
//         return totalWays;
//     }

//     int checkRecord(int n) {
//         dp.assign(5, vector<vector<vector<int>>>(3, vector<vector<int>>(n + 1, vector<int>(3, -1))));
//         long long totalWays = 0;
//         totalWays += solve(0, 0, 0, 1, n)%MOD;
//         totalWays += solve(1, 0, 1, 1, n)%MOD;
//         totalWays += solve(0, 1, 2, 1, n)%MOD;
//         totalWays %= MOD;
//         return totalWays;
//     }
// };


// class Solution {
// public:
//     vector<vector<vector<vector<int>>>>dp;
//     int MOD= 1000000007;
//     int solve(int con_L , int con_A, int curr, int k, int n){
//         if(k==n){
//            return (con_L < 3 && con_A < 2) ? 1 : 0;
//         }
//         if(con_L>=3 || con_A>=2){return 0;}
//         if(dp[con_L][con_A][k][curr]!=-1){return dp[con_L][con_A][k][curr]%MOD;}

//         int ans=0;
//         ans+=(solve(con_L+1, 0, 1,k+1, n)%MOD);
//         ans+=(solve(0,con_A+1,2, k+1, n)%MOD);
//         ans= ans%MOD;
//         ans+=(solve(0, 0 , 0, k+1,n)%MOD);
//         dp[con_L][con_A][k][curr]=ans%MOD;
//         return dp[con_L][con_A][k][curr];

//     }
//     int checkRecord(int n) {
//         dp.assign(5,vector<vector<vector<int>>>(3, vector<vector<int>>(n+1, vector<int>(3, -1))));
//         int ans=0;
//         ans+=(solve(0, 0, 0, 1,n)%MOD);
//         ans+=(solve(1, 0, 1, 1,n)%MOD);
//         ans= ans%MOD;
//         ans+=(solve(0, 1, 2, 1,n)%MOD);
//         return ans;

//     }
// };



// class Solution {
// public:
//     vector<vector<vector<int>>> dp;
//     int MOD = 1000000007;

//     int solve(int con_L, int con_A, int k, int n) {
//         if (k == n) {
//             return (con_L < 3 && con_A < 2) ? 1 : 0;
//         }
//         if (con_L >= 3 || con_A >= 2) {
//             return 0;
//         }
//         if (dp[con_L][con_A][k]!= -1) {
//             return dp[con_L][con_A][k] % MOD;
//         }

//         int ans = 0;
//         ans = (ans + solve(con_L + 1, 0, k + 1, n)) % MOD; // Late
//         ans = (ans + solve(0, con_A + 1, k + 1, n)) % MOD; // Absent
//         ans = (ans + solve(0, 0, k + 1, n)) % MOD; // Present

//         dp[con_L][con_A][k] = ans % MOD;
//         return dp[con_L][con_A][k];
//     }

//     int checkRecord(int n) {
//         dp.assign(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        
//         int ans = solve(0, 0, 0, n);
//         return ans;
//     }
// };



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long  MOD = 1000000007;

    long long solve(int con_L, int con_A, int k, int n) {
        if (k == n) {
            return (con_L < 3 && con_A < 2) ? 1 : 0;
        }
        if (con_L >= 3 || con_A >= 2) {
            return 0;
        }
        if (dp[con_L][con_A][k] != -1) {
            return dp[con_L][con_A][k] % MOD;
        }

        long  ans = 0;
        ans = (ans%MOD + solve(con_L + 1, con_A, k + 1, n)%MOD) % MOD; // Late
        ans = (ans%MOD+ solve(0, con_A + 1, k + 1, n)%MOD) % MOD; // Absent
        ans = (ans%MOD + solve(0, con_A, k + 1, n)%MOD) % MOD; // Present

        dp[con_L][con_A][k] = ans % MOD;
        return dp[con_L][con_A][k];
    }

    int checkRecord(int n) {
        dp.assign(4, vector<vector<long long>>(3, vector<long long >(n + 1, -1)));
        long long  ans = (solve(0, 0, 0, n) % MOD);
        return ans;
    }
};


