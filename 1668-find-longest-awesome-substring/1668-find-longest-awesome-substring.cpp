class Solution {
public:
    map<int, int> mp;  

    int longestAwesome(string s) {
        int mask = 0;  
        int n = s.size(), ans = 0;
        mp[0] = -1;

        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                mask ^= (1 << 0);  
            } else if (s[j] == '1') {
                mask ^= (1 << 1);  
            } else if (s[j] == '2') {
                mask ^= (1 << 2);  
            } else if (s[j] == '3') {
                mask ^= (1 << 3); 
            } else if (s[j] == '4') {
                mask ^= (1 << 4);  
            }
            else if (s[j] == '5') {
                mask ^= (1 << 5);  
            }
            else if (s[j] == '6') {
                mask ^= (1 << 6);  
            }
            else if (s[j] == '7') {
                mask ^= (1 << 7);  
            }
            
            else if (s[j] == '8') {
                mask ^= (1 << 8);  
            }
            else if (s[j] == '9') {
                mask ^= (1 << 9);  
            }
    
            if (mp.find(mask) != mp.end()) {
                int index = mp[mask];
                ans = max(ans, j - index); 
            }
            else {
                mp[mask] = j; 
            }
            
            for(int k=0; k<=9; k++){
                 int cur=mask; 
                 cur =cur^(1<<k);
                 if (mp.find(cur) != mp.end()) {
                     int idx = mp[cur];
                     if((j-idx)%2==1){
                        ans = max(ans, j- idx); 
                     }
                     
                }   
            }

        }

        return ans;
    }
};
