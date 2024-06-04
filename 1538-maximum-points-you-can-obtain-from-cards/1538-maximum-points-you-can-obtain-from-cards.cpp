class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0, ans=0;
        if(k==1){return max(cardPoints[0], cardPoints[cardPoints.size()-1]);}
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
       ans=max(ans,sum);
       sum-=cardPoints[k-1]; 
       sum+=cardPoints[cardPoints.size()-1];
       ans=max(ans,sum);
       int i=k-2;
       int j=cardPoints.size()-2;
       while(i>=0){
       sum-=cardPoints[i];
       sum+=cardPoints[j];
       i--; j--;
       ans=max(ans,sum);
       }
       int sum2=0;
       for(int i=cardPoints.size()-1; i>cardPoints.size()-k-1; i--){
       sum2+= cardPoints[i];
       
       }
       ans= max(ans, sum2);
       return ans;

    }
};