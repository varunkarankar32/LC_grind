#define P pair<int, int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busyRooms;

        vector<int> meetingCount(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                busyRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [earliestEnd, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({earliestEnd + duration, room});
                meetingCount[room]++;
            }
        }
        int maxMeetings = 0;
        int bestRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                bestRoom = i;
            }
        }

        return bestRoom;
    }
};