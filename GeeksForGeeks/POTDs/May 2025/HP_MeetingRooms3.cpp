#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
    vector<int> freq(n, 0);

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap of available rooms (by room index)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        // Min-heap of {endTime, roomIndex}
        typedef pair<long long, int> PII;
        priority_queue<PII, vector<PII>, greater<PII>> occupiedRooms;

        for (const auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free rooms that are done before the meeting starts
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                int room = occupiedRooms.top().second;
                occupiedRooms.pop();
                availableRooms.push(room);
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({end, room});
                freq[room]++;
            } else {
                PII top = occupiedRooms.top();  // fallback for C++11/14
                occupiedRooms.pop();
                long long endTime = top.first;
                int room = top.second;

                long long duration = end - start;
                occupiedRooms.push({endTime + duration, room});
                freq[room]++;
            }
        }

        // Find the room with the most meetings
        int maxFreq = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[i] > maxFreq || (freq[i] == maxFreq && i < result)) {
                maxFreq = freq[i];
                result = i;
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}