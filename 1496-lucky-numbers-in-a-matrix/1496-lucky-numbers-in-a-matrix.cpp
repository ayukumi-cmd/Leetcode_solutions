// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& nums) {
//         int n= nums.size();
//         int m= nums[0].size();
//         vector<int>ans;
 
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 int el= nums[i][j];
//                 bool f= true;
//                 for(int k=0; k<i; k++){
//                  if(el<=nums[k][j]){
//                     f=false; 
//                     break;
//                  }
//                 }
            
//                 for(int k=0; k<j; k++){
//                  if(el>=nums[i][k]){
//                     f=false; 
//                     break;
//                  }
//                 }
//                 if(f==false){ans.push_back(el);}
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
   
            int minElement = matrix[i][0];
            int minIndex = 0;
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = j;
                }
            }

        
            bool isLucky = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][minIndex] > minElement) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) {
                ans.push_back(minElement);
            }
        }

        return ans;
    }
};
