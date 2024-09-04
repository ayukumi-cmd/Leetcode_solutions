class Solution {
public:
    using p= pair<int,int>;
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>>mp; 
        int n= arr.size();
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n, false);
        vis[0]=true;
        priority_queue<p , vector<p>, greater<p>>pq;
        pq.push({0,0}); 
     
        while(!pq.empty()){
            auto x= pq.top();
            int steps=x.first; int node= x.second;
            pq.pop();
            if(node==n-1){
                return steps;
            }
            vector<int>pos= mp[arr[node]];
            pos.push_back(node-1); 
            pos.push_back(node+1);

            for(auto it:pos){
                if(it>=0 and it<n and !vis[it]){
                    vis[it]=true; 
                    pq.push({steps+1, it});
                }
            }
            mp.erase(arr[node]);
            
            
        }
        return -1;
    }
};