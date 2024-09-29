class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans=0; 
        k--;
        while(k!=0){
                long long  x= log2(k);
                cout<<x<<endl;
                ans+=operations[x];
                k= k-pow(2, x);
              
        }
        ans=ans%26; 
        return 'a'+ans;
    }
};