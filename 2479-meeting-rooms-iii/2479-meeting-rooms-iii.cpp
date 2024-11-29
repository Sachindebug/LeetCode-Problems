#define int1 long long
class Solution {
public:
    int mostBooked(int1 n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        map<int1,int1> count;
        priority_queue<int1,vector<int1>,greater<>> available;
        priority_queue<pair<int1,int1>, vector<pair<int1,int1>>,greater<>> used; // end_time, room number
        for(int1 i = 0; i<n; i++) available.push(i);

        // iterate over meetings
        for(auto meeting: meetings){
            int1 start  = meeting[0];
            int1 end = meeting[1];
            while(!used.empty() && used.top().first <= start){
                auto tp = used.top();
                used.pop();
                available.push(tp.second);
            }
            if(available.empty()){
                auto tp = used.top();
                used.pop();
                end = tp.first + (end-start);
                available.push(tp.second);
            }
            int1 availableRoom = available.top();
            available.pop();
            count[availableRoom]++;
            used.push({end,availableRoom});
        }
        int1 requiredRoomNumber = 0;
        int1 maxMeetings = 0;
        for(auto x: count){
            if(x.second > maxMeetings) {
                maxMeetings = x.second;
                requiredRoomNumber = x.first;
            }
        }
        return requiredRoomNumber;
    }
};