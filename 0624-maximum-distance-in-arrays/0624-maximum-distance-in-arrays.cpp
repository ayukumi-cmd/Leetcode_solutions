class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int minVal = arr[0][0];
        int maxVal = arr[0].back();
        int maxDistance = 0;

        for(int i = 1; i < arr.size(); i++) {
            int x= arr[i][0]; 
            int y= arr[i].back();

      
            maxDistance = max(maxDistance, max(abs(y - minVal), abs(maxVal - x)));

            minVal = min(minVal, x);
            maxVal = max(maxVal, y);
        }

        return maxDistance;
    }
};