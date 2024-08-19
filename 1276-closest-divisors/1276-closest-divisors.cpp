using ll =long long int;
class Solution {
public:
    vector<int> closestDivisors(int num) {
        ll x= num+1; 
        ll y= num+2; 
        ll l1=0, l2=0;
        for(int i=1; i<=sqrt(x); i++){
            if(x%i==0){
            l1=i; l2=x/i;
            }
        }
        ll a1=0, a2=0;
        for(int i=1; i<=sqrt(y); i++){
            if(y%i==0){
            a1=i; a2=y/i;
            }
        }
        vector<int>ans;
        if(abs(a1-a2)<abs(l1-l2)){
             ans.push_back(a1); ans.push_back(a2);
        }
        else {
            ans.push_back(l1); ans.push_back(l2);
        }
        return ans;
    }
};