class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        stack<int> s;
        s.push(-1);
        int n=nums.size();
        vector<long long> nextGreaterIndex(n,0);
        for(int i=n-1;i>=0;i--){
            if(s.top()==-1||nums[s.top()]>nums[i]){
                nextGreaterIndex[i]=s.top();
                s.push(i);
            }
            else{
                while(s.top()!=-1&&nums[s.top()]<=nums[i]){
                    s.pop();
                }
                nextGreaterIndex[i]=s.top();
                s.push(i);
            }   
        }
        long long ans=0;
        long long j=0;
        while(j<n){
            if(nextGreaterIndex[j]==-1){
                ans+=(long long)(n-1-j)*nums[j];
                break;
            }
            ans+=(nextGreaterIndex[j]-j)*nums[j];
            j=nextGreaterIndex[j];
        }
        return ans;
    }
};