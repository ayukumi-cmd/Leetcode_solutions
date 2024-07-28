class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=points.size();
        int m=queries.size();
         vector<int>ans;
        for(int i=0; i<m; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                int check= pow(points[j][0]-queries[i][0],2)+pow(points[j][1]-queries[i][1],2)-
                pow(queries[i][2],2);

                if(check<=0){cnt++;}
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};