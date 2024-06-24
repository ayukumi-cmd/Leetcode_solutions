class Solution {
public:
    double minimumAverage(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        double ans=1000;
        while(i<j) {
            double k = (v[i]+v[j])/(2*1.0);
            ans=min(ans,k);
            i++;
            j--;
        }
        return ans;
    }
};