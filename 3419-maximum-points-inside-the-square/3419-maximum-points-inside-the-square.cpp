class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n=points.size(); 
        vector<pair<int, int>>max_cor;
        for(int i=0; i<n; i++){
         max_cor.push_back({max(abs(points[i][0]), abs(points[i][1])),s[i]});
        }
        sort(max_cor.begin(), max_cor.end());
        vector<int>vis(26,0); int ans=0;
         for(int i=0; i<n; i++){
          if(vis[(max_cor[i].second)-'a']==0){vis[(max_cor[i].second)-'a']=1; ans++;}
          else {
          if(max_cor[i].first==max_cor[i-1].first){ans--; break;}
          else break;
          }
         }
         return ans;

    }
};