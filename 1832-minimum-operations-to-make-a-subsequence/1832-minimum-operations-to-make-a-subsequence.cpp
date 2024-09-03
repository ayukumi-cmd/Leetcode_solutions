class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n1 = target.size();
        int n2 = arr.size();
   
        unordered_map<int, int> m;
        for (int i = 0; i < n1; i++) {
            m[target[i]] = i;
        }
        
        vector<int> v;
        for (int i = 0; i < n2; i++) {
            if (m.find(arr[i]) != m.end()) {
                v.push_back(m[arr[i]]);
            }
        }

        if (v.empty()) {
            return n1; 
        }

        vector<int> seq;
        seq.push_back(v[0]);
        
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > seq.back()) {
                seq.push_back(v[i]);
            } else {
                auto it = lower_bound(seq.begin(), seq.end(), v[i]);
                int indx= static_cast<int>(it-seq.begin());
                seq[indx]= v[i];
            }
        }
        
        return n1 - seq.size(); 
    }
};
