class Solution {
public:

   int solve(vector<int>&arr){
    vector<int> temp;
    temp.push_back(arr[0]);
    int n= arr.size();
    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;

   }
   static bool cmp(vector<int>&a, vector<int>&b){
    if(a[0]<b[0]){return true;}
    if(a[0]>b[0]){return false;}
    else{return a[1]>b[1];}
   }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int>height;
        for(auto it:envelopes){height.push_back(it[1]);}

       return solve(height);
    }

};


