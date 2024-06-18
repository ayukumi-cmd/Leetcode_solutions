#define ll long long 
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int>bit(32,0);
        for(ll i=0; i<nums.size(); i++){
            for(ll j=0; j<32; j++){
                bool jth_bit=(1<<j)&nums[i];
                if(jth_bit==true){
                    bit[j]++;
                }
            }
        }

        ll ans=0;
        for(ll j=0; j<32; j++){
            if(bit[j]%2==0 and bit[j]!=0){
            ans+=pow(2, j);
            }
            else if(bit[j]%2==1){
                ans+=pow(2, j);
            }
        }

        return ans;
    }
};