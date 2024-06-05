class Solution {
public:
    void monotonicadd(deque<int>&dq,int i, vector<int>&nums){
    while((!dq.empty()) && nums[dq.back()]<=nums[i]) dq.pop_back();
    dq.push_back(i);
    }
    int biggest(deque<int>&dq,int i, vector<int>&nums, int k){
        while((!dq.empty())&& i-dq.front()>=k) dq.pop_front();
        if(!dq.empty() and nums[dq.front()]>0){
            return nums[i]+nums[dq.front()];
        }
        else return nums[i];

    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n= nums.size();
        deque<int>dq;
        for(int i=0; i<n; i++){
            nums[i]=biggest(dq, i,nums, k+1);
            monotonicadd(dq,i,nums);
        }
        return *max_element(nums.begin(), nums.end());
    }
};

