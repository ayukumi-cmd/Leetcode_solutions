class Solution {
public:
const int MAXN = 1e5 + 1, MOD = 1e9 + 7;

int sumOfFlooredPairs(vector<int>& nums) {
    vector<long> freq(2 * MAXN + 1);        
    long mx = 0, sum = 0;
    vector<long >freq_el(2*MAXN+1);
    for(auto num : nums) {
        freq_el[num]++;
        ++freq[num];
        mx = max((int)mx, num);
    }



    sort(nums.begin(), nums.end());

    vector<int>number;
    for(auto el:nums){
     if(number.empty()|| number.back()!=el){
        number.push_back(el);
     }
     else continue;
    }

    for(int i = 1; i <= 2 * MAXN; ++i) {
        freq[i] += freq[i - 1];
    }

    for(auto num : number) { 
        long l = num, r = 2 * num - 1, divResult = 1;
        long freq_of_el=freq_el[num];
        while(l <= mx) {                
            sum = (sum + divResult *freq_of_el* (freq[r] - freq[l - 1])) % MOD;
            l += num;
            r += num;
            ++divResult;
        }
    }

    return sum;
}

};