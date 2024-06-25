class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2){
        if(p1.first == p2.first) return p1.second >p2.second;
        else return p1.first >p2.first;
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(&cmp);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            if(i >= nums.size() - k){
                auto f = pq.top();
                pq.pop();

                int ind = f.second;
                ans.push_back(f.first);

                while(!pq.empty() && pq.top().second <ind) pq.pop();
            }
        }
        return ans;
    }
};