class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n=colors.size();
        int j=0; 
        int i=0; 
        vector<int>temp=colors;
        for(int i=0; i<n; i++){
          colors.push_back(temp[i]);
        }

        int cnt=0;
        
        while(j<=n+k-2 and i<n){
        if(colors[j+1]!=colors[j]){
            j++;
        }
        else if(colors[j]==colors[j+1]){
            
            j++;
            i=j;
        }


        if(j-i+1==k){
            cnt++;
            i++;
        }
        
        
        
        }
    
     return cnt;

    }
};