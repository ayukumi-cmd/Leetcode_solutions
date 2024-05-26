class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, long long >mp1;
        unordered_map<long long , long long >mp2;
        for(auto &el: nums1){mp1[el]++;}
        for(auto &el: nums2){mp2[el]++;}
        long long ans=0;
        for(auto el:mp1){
            long long  num=el.first;
            for(long long  i=1;i<=sqrt(num);i++){
                if(num%i==0 and i%k==0 and num%(i/k)==0 and mp2.find(i/k)!=mp2.end()){
                auto it= mp2.find(i/k);
                ans+=(el.second)*(it->second);
                }
                
                if(num%i==0 and (num/i)%k==0 and num%((num/i)/k)==0 and mp2.find((num/i)/k)!=mp2.end() and i!=num/i){
                auto it=mp2.find((num/i)/k);
                ans+=(el.second)*(it->second);
                }
            }
           
        }
      
          return ans;
    }
};