class Solution {
public:
    string nearestPalindromic(string n) {
        long long nl = stoll(n);
        int len = n.length();

      
        if (nl <= 10 || (nl % 10 == 0 and n[0]=='1' && stoll(n.substr(1)) == 0)) {
            return to_string(nl - 1);
        }
        
        if (nl == 11 || (nl % 10 == 1 && n[0] == '1' && stoll(n.substr(1, len - 2)) == 0)) {
            return to_string(nl - 2);
        }

        if (isAllDigitNine(n)) {
            return to_string(nl + 2);
        }

   
        bool isEvenDigits = len % 2 == 0;
        string palindromeRootStr = isEvenDigits ? n.substr(0, len / 2) : n.substr(0, len / 2 + 1);
        long long palindromeRoot = stoll(palindromeRootStr);
        
        long long equal = toPalindromeDigits(to_string(palindromeRoot), isEvenDigits);
        long long diffEqual = abs(nl - equal);
            
        long long bigger = toPalindromeDigits(to_string(palindromeRoot + 1), isEvenDigits);
        long long diffBigger = abs(nl - bigger);
        
        long long smaller = toPalindromeDigits(to_string(palindromeRoot - 1), isEvenDigits);
        long long diffSmaller = abs(nl - smaller);
         

        long long closest = (diffBigger < diffSmaller) ? bigger : smaller;
        long long minDiff = min(diffBigger, diffSmaller);
        
        if (diffEqual != 0) { 
            if (diffEqual == minDiff) { 
                closest = min(equal, closest);
            } else if (diffEqual < minDiff){
                closest = equal;
            }
        }
        
        return to_string(closest);
    }
    
private:
    long long toPalindromeDigits(string num, bool isEvenDigits) {
        string reversedNum = string(num.rbegin(), num.rend());
        string palindromeDigits = isEvenDigits
            ? num + reversedNum
            : num + reversedNum.substr(1);
        return stoll(palindromeDigits);
    }
    
    bool isAllDigitNine(const string& n) {
        for (char ch : n) {
            if (ch != '9') {
                return false;
            }
        }
        return true;
    }
};
