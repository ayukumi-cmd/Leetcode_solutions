class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
         sort(items.begin(), items.end());
         int n= items.size();
         vector<int>vp; 
         vector<int>be;
         int max_beauty= INT_MIN;
        for(int i=0; i<n; i++){
         int price=items[i][0]; 
         int beauty= items[i][1]; 
         max_beauty= max(max_beauty,beauty);
         vp.push_back(price);
         be.push_back(max_beauty);
       }
       vector<int>ans;
       for(int i=0; i<queries.size(); i++){
        int q= queries[i]; 

        int l=0; int h=vp.size()-1; 
        int idx=-1;

        while(l<=h){
            int mid= l+(h-l)/2; 

            if(vp[mid]<=q){
                idx=mid; 
                l= mid+1; 
            }
            else {
                h= mid-1; 
            }
        }
        if(idx==-1){ans.push_back(0);}
        else {
            ans.push_back(be[idx]);
        }
       }
       return ans;
    
    }
};