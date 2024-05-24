class Solution {
public:
    bool binarySearch(vector<int>& nums, vector<int>& changeIndices, int idx) {
        int n= nums.size();
        vector<int>last(n, -1);
        for (int i = 0; i <=idx; i++) {
            last[changeIndices[i]] = i;
        }
      
        int power = 0; 
        int cnt=0;
        for (int i = 0; i <=idx; i++) {
            if (i == last[changeIndices[i]]) {
                if (power < nums[changeIndices[i]]) return false;
                else{ power -= nums[changeIndices[i]]; cnt++;}
                
            } else {
                power++;
            }
        }
        return cnt==n;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        vector<int>indices=changeIndices;
        for(auto &el:indices){el--;}
        int l = 0, r =m-1;
        int ans=-1;
        while (l <=r) {
            int mid = l + (r - l) / 2;
            if (binarySearch(nums, indices, mid)) {
                r = mid-1;
                ans= mid;
            } else {
                l = mid + 1;
            }
        }
        return ans==-1? -1 : ans+1;
    }
};