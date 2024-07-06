class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        
        long long points = 0;
        long long current =currentEnergy;
        long long j = enemyEnergies.size() - 1;
        if(currentEnergy<enemyEnergies[0]){
            return 0;
        }
        while (j>=0) {
            if (current >= enemyEnergies[0]) {
                current -= enemyEnergies[0];
                points++;
            }if (points > 0) {
                current+= enemyEnergies[j];
                j--;
            } else {
                break;
            }
        }

        points+=(current/enemyEnergies[0]);
        return points-1;
    }
};
