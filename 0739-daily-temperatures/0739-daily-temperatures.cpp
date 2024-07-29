class Solution {
public:
    vector<int> dailyTemperatures( vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack <int> stk;  
        for(int i=temp.size()-1;i>=0;i--){
            if(stk.empty()){
                stk.push(i);
                ans[i] = 0;
            }
            else{

           
                while(!stk.empty() && temp[i]>=temp[stk.top()]){
                    stk.pop();
                }

                if(stk.empty()){
                    ans[i] = 0;
                }
                else{
                    ans[i] = stk.top()-i;
                }
                stk.push(i);
            }
            
        }
        return ans;
    }
}; 