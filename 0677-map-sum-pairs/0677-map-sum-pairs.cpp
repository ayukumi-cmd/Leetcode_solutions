class MapSum {
public:
    unordered_map<string, int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
       mp[key]=val;
    }
    
    int sum(string prefix) {
        int sum=0;
        int sz= prefix.length();

        for(auto it:mp){
            string check =it.first;
             bool f=true;
            for(int i=0;i<sz; i++){
                if(check[i]!=prefix[i]){f=false ; break;}
            }
            if(f){sum+=it.second;}
        }
        return sum;

    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */