
class Solution {
public:
  int findpar(int node, vector<int>&par){
      if(par[node]==node)   return node;
      return par[node]=findpar(par[node], par);
  }
  
  void unionByRank(int u,int v, vector<int>&rank , vector<int>&par){
      int pu=findpar(u, par);
      int pv=findpar(v, par);
      
      if(pu==pv)    return;
      
      if(rank[pu]<rank[pv])     par[pu]=pv;
      else if(rank[pv]<rank[pu])    par[pv]=pu;
      else{
          par[pv]=pu;
          rank[pu]++;
      }
  }
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        unordered_map<string,int> mp;
        vector<int>parent(a.size()) ;for(int i=0; i<a.size(); i++){parent[i]=i;}
         vector<int>rank(a.size(),0);

        for(int i=0;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                string str=a[i][j];
                if(mp.find(str)==mp.end())  mp[str]=i;
                else{
                    unionByRank(mp[str],i, rank, parent);
                }
            }
        }

        vector<string> res[a.size()];
        for(auto it:mp){
            string s=it.first;
            int node=findpar(it.second, parent);
            // cout<<s<<" "<<node<<endl;
            res[node].push_back(s);
        }

        vector<vector<string>> ans;
        for(int i=0;i<a.size();i++){
            vector<string> tmp=res[i];
            if(tmp.size()==0)   continue;
            sort(tmp.begin(),tmp.end());
            tmp.insert(tmp.begin(),a[i][0]);
            ans.push_back(tmp);
        }
        return ans;
    }
};