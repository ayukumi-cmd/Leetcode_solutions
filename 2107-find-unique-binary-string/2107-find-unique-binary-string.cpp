class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // george cantor diagonolization argument 


    //    s1= 01010
    //    s2= 01111
    //    s3= 11010
    //    s4= 10101
    //    s5= 01010

    //    now make a unique binary sequence which doesnt resemble to any of the given seq

    //    t =10111 


    //implementation 
    string s;
    for(int i=0; i< nums.size(); i++){
      if(nums[i][i]=='1'){
        s+='0';
      }
      else {
        s+='1';
      }
    }

    return s;

        
    }
};