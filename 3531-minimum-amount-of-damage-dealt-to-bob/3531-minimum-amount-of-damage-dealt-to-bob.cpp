class Solution {
public:
    static bool cmp(pair< double,pair<int, int>>&a, pair< double,pair<int, int>>&b){
        if(a.first<b.first){
            return false;
        }
        else if(a.first>b.first){
            return true;
        }
        else {
           if(a.second.second>b.second.second){
            return true;
           }
           else return false ;
        }
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long n = health.size();
        vector<long long> time;
        vector<pair< double,pair<int, int>>> arr; 
        
        for(int i=0;i<n;i++){
            time.push_back(1LL*ceil((1.0*health[i])/(1.0*power)));
            double dps = 1LL*(1.0*damage[i])/(1.0*time[i]);
            pair<int,int> p= make_pair(i, damage[i]);
            arr.push_back({dps,p});
        }
        
        sort(arr.begin(), arr.end(), cmp);
        long long ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum += (1LL*arr[i].second.second);
        }
        for(int i=0;i<n;i++){
            ans += 1LL*sum*(time[arr[i].second.first]);
            sum -= arr[i].second.second;
        }
        return ans;
    }
};