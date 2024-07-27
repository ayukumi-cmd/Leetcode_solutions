class MyCalendarThree {
public:
   map<int, int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int ans=0 ;
        int res=INT_MIN;
        for(auto it: mp){
            ans+=it.second;
            res=max(res, ans);
        }
        return res;
    }
};

