
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int, int> events;

  
        for (const auto& flower : flowers) {
            events[flower[0]]++;
            events[flower[1] + 1]--;
        }

  
        vector<pair<int, int>> sortedEvents(events.begin(), events.end());
        sort(sortedEvents.begin(), sortedEvents.end());


        vector<int> bloomCounts;
        vector<int> times;
        int currentBloomCount = 0;
        for (const auto& event : sortedEvents) {
            currentBloomCount += event.second;
            times.push_back(event.first);
            bloomCounts.push_back(currentBloomCount);
        }


        vector<int> result;
        for (int time : people) {
            auto it = upper_bound(times.begin(), times.end(), time);
            if (it == times.begin()) {
                result.push_back(0);
            } else {
                result.push_back(bloomCounts[it - times.begin() - 1]);
            }
        }

        return result;
    }
};
