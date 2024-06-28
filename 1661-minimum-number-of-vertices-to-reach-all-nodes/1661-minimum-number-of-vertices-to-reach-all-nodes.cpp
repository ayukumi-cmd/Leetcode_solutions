#define ll long long 
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<ll>indegree(n, 0);
        for(auto it:edges){
            indegree[it[1]]++;
        }

        vector<int>ans; 
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){ans.push_back(i);}
        }
        return ans;

    }
};