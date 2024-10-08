class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startValue){
            if(target%2){
                target++; 
                target/=2;
                ans+=2;
            }
            else {
                target/=2;
                ans++;
            }
        }
        ans+=startValue-target;
        return ans;
    }
};