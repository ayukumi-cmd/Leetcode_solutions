class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()==1 ||arr.size()==2 ||arr.size()==0){return 0;}
        for(int i=0; i<arr.size()-2; i++){
        if(arr[i]%2==1 and arr[i+1]%2==1 and arr[i+2]%2==1){
            return true;
        }
        }
        return false;
    }
};