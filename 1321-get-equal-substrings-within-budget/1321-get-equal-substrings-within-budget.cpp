class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        vector<int>cost(n, 0);
        
        for(int i=0; i<n; i++){
        cost[i]=abs((s[i]-'0')-(t[i]-'0'));
        }
        int i=0; int j=0;
        int costii=0;
        int len=INT_MIN;
        while(i<=j and j<n){
         costii+=cost[j];
         if(costii<=maxCost){len= max(len,j-i+1);}
            while(costii>maxCost and i<=j){
             costii-=cost[i];
             i++;
            }
           j++;
        }
        return len==INT_MIN?0 :len;
    }
};