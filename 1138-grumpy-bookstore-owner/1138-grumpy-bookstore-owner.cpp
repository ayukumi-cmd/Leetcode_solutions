#define ll long long
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ll n= grumpy.size();
        ll sum=0; ll maxi=LLONG_MIN;

        ll ans=0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0){ans+=customers[i];}

            if(grumpy[i]==1 and i<minutes){
                sum+=customers[i];
            }

            if(i>=minutes){
                maxi= max(sum, maxi);
                if(grumpy[i-minutes]==1){
                    sum-=customers[i-minutes];
                }
                if(grumpy[i]==1){
                    sum+=customers[i];
                }
            }
        }
        maxi= max(sum, maxi);
        return ans+maxi;


    }
};