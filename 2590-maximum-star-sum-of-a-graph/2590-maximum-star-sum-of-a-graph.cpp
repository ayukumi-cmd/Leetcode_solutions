class Solution {
public:
    int maxStarSum(vector<int>& val, vector<vector<int>>& edges, int k) {
        int n= val.size();
        vector<int>adj[n];
        if(k==0||edges.size()==0){return *max_element(val.begin(), val.end());}
        for(auto it:edges){
            int from=it[0];
            int to=it[1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int ans=INT_MIN;
        for(int i=0; i<= n-1; i++){
            vector<int>temp;
            for(auto nbh:adj[i]){
             temp.push_back(val[nbh]);
            }
            sort(temp.begin(), temp.end(), greater<int>());
            
            int sum=0; int cnt=0;
            for(int j=0; j<temp.size(); j++){
                if(temp[j]<0){break;}
                else if(cnt!=k){sum+=temp[j]; cnt++;}
            }
              sum+=val[i];
             ans= max(ans, sum);
        }
        return ans;
    }
};