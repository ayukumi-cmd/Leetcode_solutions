class Solution {
public:
long long  minOperationsToMakeMedianK(vector<int> a, int X) 
{ 

    sort(a.begin(), a.end()); 
    long long ans = 0; 

    int n = a.size(); 

    for (int i = 0; i < n; i++) { 

        if (i < n / 2) 
            ans += max(0, a[i] - X); 

        else if (i == n / 2) 
            ans += abs(X - a[i]); 

        else
            ans += max(0, X - a[i]); 
    } 

    return ans; 
} 
};
