class Solution {
public:
    using p=pair<int,int>;
    void nextPermutation(vector<int>& nums) {

        int n= nums.size();
        priority_queue<p, vector<p>, greater<p>>pq;


        pq.push(make_pair(nums[n-1], n-1));

        bool f= false;

        for(int i=n-2; i>=0; i--){
           if(nums[i]<nums[i+1]){
            while(!pq.empty()){
                int idx=pq.top().second; 
                int el= pq.top().first;
                pq.pop();
                if(el>nums[i]){
                swap(nums[i], nums[idx]); 
                sort(nums.begin()+i+1,nums.end());
                 f= true; break;
                 
            }
            }
           }

           else {
           pq.push(make_pair(nums[i], i));
           }
           if(f==true){break;}

        }

        if(f==false){
            sort(nums.begin(), nums.end());
            return ;
        }
        else return ;
    }
};