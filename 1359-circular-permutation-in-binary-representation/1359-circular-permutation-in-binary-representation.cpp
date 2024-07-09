class Solution {
public:
 vector<int> grayCode(int n)
   {
      vector<int>v;
      for(int i=0 ;i<(1<<n);i++)
      v.push_back(i^(i>>1));
      return v;
   }
    vector<int> circularPermutation(int n, int start) {
    vector<int>build=grayCode(n);

    int index=0;

    for(int i=0; i<(1<<n); i++){
        if(build[i]==start){
            index=i; break;
        }
    }

    vector<int>ans;
    
    int i=0;
    while(ans.size()!=(1<<n)){
      ans.push_back(build[(index+i)%(1<<n)]);
      i++;
    }
    return ans;

    }
};