
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int v1 = version1.size(), v2 = version2.size();
        
        while (i1 < v1 && i2 < v2) { 
            int num1 = 0, num2 = 0;
            while (i1 < v1 && version1[i1] != '.') {
                num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            while (i2 < v2 && version2[i2] != '.') {
                num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }
            
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            i1++;
            i2++;
        }
        
        while (i1 < v1) {
            int num1 = 0;
            while (i1 < v1 && version1[i1] != '.') {
                num1 = num1 * 10 + (version1[i1] - '0');
                i1++;
            }
            if (num1 != 0) return 1; 
            i1++; 
        }
        
    
        while (i2 < v2) {
            int num2 = 0;
            while (i2 < v2 && version2[i2] != '.') {
                num2 = num2 * 10 + (version2[i2] - '0');
                i2++;
            }
            if (num2 != 0) return -1; 
            i2++;
        }
        
        return 0;
    }
};