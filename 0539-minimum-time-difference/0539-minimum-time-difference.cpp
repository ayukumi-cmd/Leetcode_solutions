class Solution {
public:
    int findMinDifference(vector<string>& times) {
        int n = times.size();
        sort(times.begin(), times.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < times.size()-1; i++) {
            int diff = abs(timeDiff(times[(i)], times[i+1]));
            diff = min(diff, 1440 - diff);
            mindiff = min(mindiff, diff);
        }
        int dif= abs(timeDiff(times[0], times[n-1]));
        dif = min(dif, 1440 - dif);
        mindiff= min(mindiff, dif);

        return mindiff;
    }

private:
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};