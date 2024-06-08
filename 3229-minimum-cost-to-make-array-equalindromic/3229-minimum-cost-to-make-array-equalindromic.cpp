class Solution {
public:


long long minimumCost(vector<int>& nums) {
    // Initialize the minimum cost to a large value
    long long ans = LLONG_MAX;
    int n = nums.size();

    // Sort the numbers to find the median
    sort(nums.begin(), nums.end());

    // Calculate the median
    // If the size is odd, the median is the middle element
    // If even, we use the average of the two middle elements
    long long median = (n % 2) ? nums[n / 2] : (nums[n / 2] + nums[n / 2 - 1]) / 2;

    // Vector to store possible palindrome candidates
    vector<long long> palindromes;
    
    // Convert median to string to facilitate palindrome manipulation
    string medianStr = to_string(median);

    // Case 1: Next palindrome with one digit less (e.g., 1000 -> 999)
    palindromes.push_back(pow(10, medianStr.size() - 1) - 1);

    // Case 2: Next palindrome with one digit more (e.g., 999 -> 1001)
    palindromes.push_back(pow(10, medianStr.size()) + 1);

    // Case 3: Palindrome by mirroring the left half
    string palindrome = medianStr;
    for (int i = 0; i < medianStr.size() / 2; ++i) {
        palindrome[medianStr.size() - i - 1] = medianStr[i];
    }
    palindromes.push_back(stoll(palindrome));

    // Case 4: Palindrome by mirroring the left half with left half + 1
    string leftHalfPlusOne = to_string(stoi(medianStr.substr(0, (medianStr.size() + 1) / 2)) + 1);
    string mirroredPlusOne = leftHalfPlusOne;
    if (medianStr.size() % 2) {
        mirroredPlusOne.pop_back(); // Remove the middle digit if odd length
    }
    reverse(mirroredPlusOne.begin(), mirroredPlusOne.end());
    palindromes.push_back(stoll(leftHalfPlusOne + mirroredPlusOne));

    // Case 5: Palindrome by mirroring the left half with left half - 1
    string leftHalfMinusOne = to_string(stoi(medianStr.substr(0, (medianStr.size() + 1) / 2)) - 1);
    string mirroredMinusOne = leftHalfMinusOne;
    if (medianStr.size() % 2) {
        mirroredMinusOne.pop_back(); // Remove the middle digit if odd length
    }
    reverse(mirroredMinusOne.begin(), mirroredMinusOne.end());
    palindromes.push_back(stoll(leftHalfMinusOne + mirroredMinusOne));

    // Find the minimum cost of converting each number to a palindrome
    for (auto p : palindromes) {
        long long sum = 0;
        for (auto num : nums) {
            sum += abs(num - p);
        }
        ans = min(ans, sum);
    }

    return ans;
}

};