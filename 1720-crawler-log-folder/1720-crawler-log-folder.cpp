class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        int n=logs.size();

        for(int i=0; i<n; i++){
            if(logs[i]=="../" and cnt>0){
                cnt--;
            }
            else if(logs[i]=="../" and cnt<=0){
                continue;
            }
           else if(logs[i]=="./"){
                continue;
            }
            else {
                cnt++;
            }
        }


        if(cnt<=0){return 0;}
        else return cnt;
    }
};