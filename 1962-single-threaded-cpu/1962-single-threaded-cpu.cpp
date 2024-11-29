class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sortedTasks;
        for(int i = 0; i<tasks.size();i++){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        vector<int> order;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> processingQueue;
        long long nextTime = sortedTasks[0][0];
        int i = 0;
        while(i<sortedTasks.size() || !processingQueue.empty()){

            if(processingQueue.empty() && nextTime<sortedTasks[i][0]){
               nextTime=sortedTasks[i][0];
            }
            while(i<sortedTasks.size() && nextTime>=sortedTasks[i][0]){
                processingQueue.push({sortedTasks[i][1],sortedTasks[i][2]});
                i++;
            }
            auto tp = processingQueue.top();
            processingQueue.pop();
            nextTime += 1ll*tp.first;
            int index = tp.second;
            order.push_back(index);

        }
        return order;
    }
};