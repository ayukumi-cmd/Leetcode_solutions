class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        
        int n=str.size();
        int m=str[0].size();
        
        vector<string>vec(n,""); 
        int res=0;
       
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                vec[j]+=str[j][i]; 
            }
          
            int var=1;
            
            for(int j=1;j<n;j++)
            {
                if(vec[j]<vec[j-1]) 
                {
                    var=-1;
                    break;
                }
            }
            
            if(var==-1) 
            {
                for(int j=0;j<n;j++)
                {
                    vec[j].pop_back();
                }
                res++;
            }
        }
        
        
        return res;
    }
};