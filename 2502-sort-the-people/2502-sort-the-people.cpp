class Solution {
public:

    static bool cmp(pair<string, int>&a,pair<string, int>&b){
        return a.second>=b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>>nh;

        for(int i=0;i<heights.size(); i++){
            nh.push_back({names[i], heights[i]});
            
        }

        sort(nh.begin(), nh.end(),cmp);

        vector<string>ans;

        for(int i=0; i<heights.size(); i++){
            ans.push_back(nh[i].first);
        }
        return ans;


    }
};