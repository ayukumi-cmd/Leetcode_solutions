class Solution {
public:
     static bool comp(vector<int>&a, vector<int>&b){
     return a[1]<b[1];
     }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0; 
       
        int n= intervals.size();

        sort(intervals.begin(), intervals.end(),comp);
         int end= intervals[0][1];
          
        for(int i=1; i<n; i++){
            if(end<= intervals[i][0]){end= intervals[i][1];}
            else {
                ans++;
            }
        }


        return ans;
    }
};

