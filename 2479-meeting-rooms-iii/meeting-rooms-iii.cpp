/*
- min heap to store empty rooms -- initially push 1 to n all available at 0, 
- while allocating a meeting room we also mention when the room will be free -- <availanle time, room No> min heap will prefer available time and then meeting num
- we also need to store max meeting in a room , we can have a separate arr to store and a var to keep track of max or we cam put that also in minheap and iteratre minheap once at the end < av time, room no, no of meets>
- iterate meets , allot one by one until available rooms
- if room not availabke before start time , new start time = max(av time of room, startTime of meet) aand av time of thjat room is duration of meet + startTime
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
    int cnt[101] = {};
    sort(begin(meets), end(meets));
    priority_queue<int, vector<int>, greater<int>> avail;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
    for (int i = 0; i < n; ++i)
        avail.push(i);
    for (auto &m : meets) {
        while (!busy.empty() && busy.top().first <= m[0]) {
            avail.push(busy.top().second);
            busy.pop();
        }
        long long start = avail.empty() ? busy.top().first : m[0], duration = m[1] - m[0];
        int room = avail.empty() ? busy.top().second : avail.top();
        if (avail.empty())
            busy.pop();
        else
            avail.pop();
        ++cnt[room];
        busy.push({start + duration, room});
    }
    return max_element(begin(cnt), end(cnt)) - begin(cnt);
}
};