class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<int, int>mp1, mp2;

        for(auto it:word){
            mp1[it-'a']++;
            mp2[it-'a']++;
        }
        
       bool ans=false;
        for(auto it:mp1){
            int x=it.second-1;
            
           int y=0;
           if(x==0){
            for(auto i:mp2){
                if(i.first!=it.first){
                  y=i.second;break;
                }
            }
           }

           else if(x!=0){
            y= x;
           }

            bool f= true;
            for(auto i:mp2){
                if(i.first!=it.first){
                    if(y!=i.second){
                        f= false; break;
                    }
                }
            }


            if(f==true){
               ans=true; break;
            }
        }

        if(ans==true){return true;}
        else return false;
    }
};