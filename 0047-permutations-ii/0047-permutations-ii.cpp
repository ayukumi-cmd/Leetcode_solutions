class Solution {   
private :
    void permute(vector<int> &nums, set<vector<int>> &ans, vector<int> &temp, int index){
        if(index == nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=index; i<temp.size(); i++){
           if(temp[index]!=temp[i]){swap(temp[index] , temp[i]);} 
            permute(nums, ans, temp, index+1);
            if(temp[index]!=temp[i]){swap(temp[index] , temp[i]);}
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp = nums;
        permute(nums, ans, temp, 0);
        vector<vector<int>>fin;
        for(auto it:ans){fin.push_back(it);}
        return fin;
    }
};




