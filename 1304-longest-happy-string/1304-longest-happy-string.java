class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder sb = new StringBuilder();
        int currA = 0, currB = 0, currC = 0;  

        while (a > 0 || b > 0 || c > 0) {
            
            if ((a >= b && a >= c && currA != 2) || (currB == 2 && a > 0) || (currC == 2 && a > 0)) {
                sb.append('a');
                a--;
                currA++;
                currB = 0;
                currC = 0;
            }
          
            else if ((b >= a && b >= c && currB != 2) || (currA == 2 && b > 0) || (currC == 2 && b > 0)) {
                sb.append('b');
                b--;
                currB++;
                currA = 0;
                currC = 0;
            }
      
            else if ((c >= a && c >= b && currC != 2) || (currA == 2 && c > 0) || (currB == 2 && c > 0)) {
                sb.append('c');
                c--;
                currC++;
                currA = 0;
                currB = 0;
            }
            else {
         
                break;
            }
        }

        return sb.toString();
    }
}
