
class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        else return p1.first < p2.first;
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

                while(!pq.empty() && pq.top().second < ind) pq.pop();
            }
        }
        return ans;
    }
    vector<int> largestMerge(vector<int>& w1, vector<int>& w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        vector<int> ans;
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            if(w1[i] - w2[j]> 0){
                ans.push_back(w1[i++]);
            }
            else if(w1[i] - w2[j]< 0){
                ans.push_back(w2[j++]);
            }
            else{
                string s1(begin(w1) + i, end(w1));
                string s2(begin(w2) + j, end(w2));
                if(s1 > s2) ans.push_back(w1[i++]);
                else ans.push_back(w2[j++]);
                }
            }
            

        while(i < n1) ans.push_back(w1[i++]);
        while(j < n2) ans.push_back(w2[j++]);

        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans(k, 0);
        for(int i = 0; i <= k; i++){
            int first = i;
            int second = k - i;


            if(first > nums1.size()) break;
            if(second > nums2.size()) continue;
            vector<int> v1 = mostCompetitive(nums1, first);
            vector<int> v2 = mostCompetitive(nums2, second);
            
            vector<int> v3 = largestMerge(v1, v2);

            string s1(begin(v3), end(v3));

            string s2(begin(ans), end(ans));

            if(s1 > s2) ans = v3;
        }
        return ans;
    }
};