class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int k){
        int count = 0, j = 0;
        int i=0;
        while(i< nums1.size() and j< nums2.size()){
            if(nums1[i] + k != nums2[j]) count++;
            else {j++;}
            i++;
        }
        if(count > 2) return 0;
        return 1;
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int minEle = INT_MAX;  
        for(int i = 0; i < nums1.size(); i++){
            int x = nums2[0] - nums1[i];
            if(check(nums1, nums2, x)){
                minEle = min(minEle, x);
            }
        }
        return minEle;
    }
};