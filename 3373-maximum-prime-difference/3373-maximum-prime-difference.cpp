class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 ||n%3==0) return false;
        for(int i=5; i*i<=n; i=i+6){
            if(n%i==0|| n%(i+2)==0){return false;}
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
       int n=nums.size();
       int prev_prime=-1;
       int next_prime=-1;
       for(int i=0; i<n; i++){
        if(isprime(nums[i])){
            if(prev_prime==-1){prev_prime=i;next_prime=i;}
            else next_prime=i;
        }
       }
       
       return abs(next_prime-prev_prime); 
    }
};