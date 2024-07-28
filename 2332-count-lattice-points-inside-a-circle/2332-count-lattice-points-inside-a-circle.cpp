class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size();

        set<pair<int, int>>st;

        for(int i=0; i<n; i++){
            int c_x=circles[i][0];
            int c_y=circles[i][1];
            int radius=circles[i][2];

            int max_x=radius+c_x;
            int max_y=radius+c_y;
            int min_x=c_x-radius;
            int min_y=c_y-radius;

            for(int j=min_x; j<=max_x; j++){
                for(int k=min_y; k<=max_y; k++){
                    int dist_x=pow(j-c_x, 2);
                    int dist_y=pow(k-c_y, 2);
                    int rad2= pow(radius, 2);

                    if(dist_x+dist_y<=rad2){st.insert({j, k});}
                }
            }
        }

        return st.size();
    }
};