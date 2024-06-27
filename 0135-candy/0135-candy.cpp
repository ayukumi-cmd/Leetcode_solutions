
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> score(n, 1);

        // Left to right pass
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                score[i] = score[i - 1] + 1;
            }
        }

        // Right to left pass
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                score[i] = max(score[i], score[i + 1] + 1);
            }
        }

        // Calculate the total candies needed
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += score[i];
        }

        return sum;
    }
};
