class Solution {
public: 
    int k=0;
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds, int limit) {
        if(ind == arr.size()) {
            if(target == 0 and limit==k) {
                ans.push_back(ds); 
            }
            return; 
        }
            if(target == 0 and limit==k) {
                ans.push_back(ds); 
                return;
            }        
        // pick up the element 
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]); 
            findCombination(ind+1, target - arr[ind], arr, ans, ds, limit+1); 
            ds.pop_back(); 
        }
        // not take case 
        findCombination(ind+1, target, arr, ans, ds , limit); 
        
    }
public:
    vector<vector<int>> combinationSum3(int limit, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        vector<int>candidates;
        k=limit;
        for(int i=1; i<=9; i++){
          candidates.push_back(i);
        }



        findCombination(0, target, candidates, ans, ds, 0); 
        return ans; 
    }
};