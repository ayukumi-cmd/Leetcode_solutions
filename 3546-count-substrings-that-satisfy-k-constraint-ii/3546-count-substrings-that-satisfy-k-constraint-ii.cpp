class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> leftMost(n, 0);
        vector<int> rightMost(n, 0);

        //leftMost[j] = i; //For index j, what is the left most valid index i until which we get valid substring
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;

        while(j < n) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i++;
            }

            leftMost[j] = i;
            j++;
        }

        //rightMost[j] = i; //For index j, what is the right most valid index until which we get valid substring
        mp.clear();
        i = n-1;
        j = n-1;
        while( j >= 0) {
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k) {
                mp[s[i]]--;
                i--;
            }
            rightMost[j] = i;
            j--;
        }

        //tempValidSubstr[j] = number of valid substrings ending at index j
        vector<int> tempValidSubstr(n, 0);
        for(int j = 0; j < n; j++) {
            tempValidSubstr[j] = j - leftMost[j] + 1;
        }

        //cumSum
        vector<long long> cumSum(n, 0);
        cumSum[0] = tempValidSubstr[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + tempValidSubstr[i];
        }

        vector<long long> result;
        for(vector<int>& query : queries) {
            int low  = query[0];
            int high = query[1];

            int validRightIdx = min(high, rightMost[low]);

            long long length = validRightIdx - low + 1;

            long long tempResult = length * (length+1)/2;

            tempResult += cumSum[high] - cumSum[validRightIdx];

            result.push_back(tempResult);


        }

        return result;
      
    }
};

