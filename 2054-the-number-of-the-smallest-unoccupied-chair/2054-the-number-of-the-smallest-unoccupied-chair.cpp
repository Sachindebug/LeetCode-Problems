class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int maxOccupied = -1;
        priority_queue<int,vector<int>,greater<>> seats;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> leave;
        vector<vector<int>> timeIndex;
        for(int i = 0;i<times.size();i++){
            auto x = times[i];
            timeIndex.push_back({x[0],i,x[1]});
        }
        sort(timeIndex.begin(),timeIndex.end());
        int seatToOccupy = -1;
        for(int i = 0;i<timeIndex.size();i++){
            while(!leave.empty() && leave.top().first<=timeIndex[i][0]){
                auto x = leave.top();
                seats.push(x.second);
                leave.pop();
            }
            if(seats.empty()){
                maxOccupied+=1;
                seatToOccupy = maxOccupied;
                leave.push({timeIndex[i][2],maxOccupied});
            }
            else{
                int frontSeat = seats.top();
                seats.pop();
                leave.push({timeIndex[i][2],frontSeat});
                seatToOccupy = frontSeat;
            }
            if(timeIndex[i][1]==targetFriend) break;
        }
        return seatToOccupy;
    }
};