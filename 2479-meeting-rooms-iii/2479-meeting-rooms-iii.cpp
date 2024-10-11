class Solution {
public:
    static bool comp(pair<int, long long> &a, pair<int, long long> &b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(&comp)> occupiedRooms(comp);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        
        vector<int> roomUsage(n, 0);
        
        for (int i = 0; i < n; i++)
            freeRooms.push(i);
        
        for (int i = 0; i < meetings.size(); i++) {
            while (!occupiedRooms.empty() && occupiedRooms.top().second <= meetings[i][0]) {
                auto room = occupiedRooms.top();
                occupiedRooms.pop();
                freeRooms.push(room.first);
            }

            if (freeRooms.empty()) {
                auto nextRoom = occupiedRooms.top();
                occupiedRooms.pop();
                
                long long timeForNextMeeting = meetings[i][1] - meetings[i][0];
                long long endTime = nextRoom.second + timeForNextMeeting;
                roomUsage[nextRoom.first]++;
                occupiedRooms.push({nextRoom.first, endTime});
            } else {
                int roomIndex = freeRooms.top();
                freeRooms.pop();
                
                roomUsage[roomIndex]++;
                occupiedRooms.push({roomIndex, meetings[i][1]});
            }
        }

        int maxBookings = 0;
        int maxIndex = 0;
        for (int k = 0; k < n; k++) {
            if (roomUsage[k] > maxBookings) {
                maxBookings = roomUsage[k];
                maxIndex = k;
            }
        }

        return maxIndex;
    }
};
