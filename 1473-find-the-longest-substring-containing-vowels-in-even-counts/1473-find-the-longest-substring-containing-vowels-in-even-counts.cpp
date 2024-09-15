class Solution {
public:
    map<int, int> mp;  

    int findTheLongestSubstring(string s) {
        int mask = 0;  
        int n = s.size(), ans = 0;
        mp[0] = -1;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') {
                mask ^= (1 << 0);  
            } else if (s[j] == 'e') {
                mask ^= (1 << 1);  
            } else if (s[j] == 'i') {
                mask ^= (1 << 2);  
            } else if (s[j] == 'o') {
                mask ^= (1 << 3); 
            } else if (s[j] == 'u') {
                mask ^= (1 << 4);  
            }
            
    
            if (mp.find(mask) != mp.end()) {
                int index = mp[mask];
                ans = max(ans, j - index); 
            }
            else {
                mp[mask] = j; 
            }
            if(mask==0){ // if mask value at particular position is equal to  0 then this will result in max length 
                ans= max(ans, j+1);
            } 

        }

        return ans;
    }
};
