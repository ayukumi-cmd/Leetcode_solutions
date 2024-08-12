
class KthLargest {
public:
    int m; 
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        m = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > m) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > m) {
            pq.pop();
        }
        return pq.top();
    }
};
