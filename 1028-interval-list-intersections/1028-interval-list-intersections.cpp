class Solution {
public:

    bool static cmpa(vector<int> a, vector<int>b){
        if(a[1]<b[1]){
            return true;
        }
        else if(a[1]==b[1]){
            if(a[0]<=b[0]) return true;
            else return false;
        }
        else return false;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        sort(f.begin(), f.end(), cmpa);
        sort(f.begin(), f.end(), cmpa);

        int i=0; int j=0; 
        int n= f.size(); int m=s.size(); 
        
        vector<vector<int>>arr;

        while(i<n and j<m){
            if(f[i][1]<s[j][0]){i++;}
            else if(f[i][0]>s[j][1]){
                j++;
            }

            else {
                int x=max(f[i][0], s[j][0]);
                int y=min(f[i][1], s[j][1]);
                if(arr.size()==0){
                    arr.push_back({x,y});
                }
                else {
                    if(arr.back()[1]<x){
                        arr.push_back({x,y});
                    }
                    else {
                        arr.back()[1]= max(arr.back()[1], y);
                    }
                }
                if(y==f[i][1]){i++;}
                else if(y==s[j][1]){j++;}
            }
        }

        return arr;
    }
};