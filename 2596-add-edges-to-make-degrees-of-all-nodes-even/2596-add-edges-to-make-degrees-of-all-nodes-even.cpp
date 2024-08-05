class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>degree(n+1, 0);
        map<pair<int,int>,int>mp;

        for(auto it:edges){
            pair<int,int>tp(it[0], it[1]);
            pair<int,int>tp2(it[1], it[0]);
            mp[tp]++; mp[tp2]++;
            degree[it[0]]++;
            degree[it[1]]++;
        }


        vector<int>odd;
        for(int i=1; i<=n; i++){
          if(degree[i]%2){odd.push_back(i);}
        }
        if(odd.size()==0){return true;}
        if(odd.size()!=4 and odd.size()!=2){return false;}
       if(odd.size()==2){
        int a=odd[0], b=odd[1];
         pair<int,int>tp1(a, b);
         if(mp.find(tp1)==mp.end()){return true;}
         for(int i=1; i<=n; i++){
            if(i!=odd[0] and i!=odd[1] and degree[i]%2==0){
             if(mp.find({a,i})==mp.end() and mp.find({b, i})==mp.end()){return true; }
            }
         }

         return  false;
    
       }
        
        int a=odd[0], b=odd[1], c=odd[2], d=odd[3];
          pair<int,int>tp1(a, b);
          pair<int,int>tp2(c, d);
          pair<int,int>tp3(a, c);
          pair<int,int>tp4(b, d);
          pair<int,int>tp5(a, d);
          pair<int,int>tp6(b, c);

if(mp.find(tp1)==mp.end() and mp.find(tp2)==mp.end() ){return true;}
if(mp.find(tp3)==mp.end()  and mp.find(tp4)==mp.end() ){return true;}
if(mp.find(tp5)==mp.end()  and mp.find(tp6)==mp.end() ){return true;}
        
return false;
    }
};
