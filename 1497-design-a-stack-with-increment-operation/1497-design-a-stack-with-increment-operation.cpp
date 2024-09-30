class CustomStack {
public:
    vector<int> v; 
    int i;        
    int maxSize;    

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        v.resize(maxSize);  
        i = 0;           
    }

    void push(int x) {
        
        if (i < maxSize) {
            v[i] = x; 
            i++;      
        }
    }

    int pop() {
       
        if (i > 0) {
            i--;       
            return v[i]; 
        }
        return -1;  
    }

    void increment(int k, int val) {
       
        int limit = min(k, i); 
        for (int j = 0; j < limit; j++) {
            v[j] += val;
        }
    }
};

