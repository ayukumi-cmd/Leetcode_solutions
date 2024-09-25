class Solution {
public:
    int findUPar(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node], parent); 
    }

    void unionByrank(int u, int v, vector<int>& parent, vector<int>& size, vector<int>&rank) {
        int ulp_u = findUPar(u, parent); 
        int ulp_v = findUPar(v, parent); 
        
        if (ulp_u == ulp_v) return; 
        

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
         parent[ulp_v] = ulp_u;
         size[ulp_u] += size[ulp_v];
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int n = 1e5+1,i;
        vector<int> s(n),p(n);
        vector<int>rank(n, 0);
        for(i = 0; i < n; i++){
            s[i] = 1, p[i] = i;
        }
        for(auto &j: nums){
            for(i = 2; i <= sqrt(j); i++){
                if(j%i==0){
                    unionByrank(i,j,p,s, rank);
                    unionByrank(j/i,j, p, s, rank);
                }
            }
        }
        int ans = INT_MIN;
        unordered_map<int,int> mp;
        for(auto &i: nums){
            mp[findUPar(i,p)]++;
            ans = max(ans,mp[findUPar(i,p)]);
        }
        return ans;
    }
};