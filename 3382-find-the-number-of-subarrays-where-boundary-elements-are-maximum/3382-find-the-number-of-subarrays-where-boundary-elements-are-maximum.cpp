class Solution {
public:
    long long numberOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        stack<int> st;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(!st.empty() && arr[i]>st.top()){
                mp[st.top()]--;
                st.pop(); 
            }
             st.push(arr[i]);
            ans+=mp[arr[i]];
        }
        return ans;
    }
};