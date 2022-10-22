class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum=0;
        int prev=customers[0][0];
        for(int i=0;i<customers.size();i++)
        {
            int a=prev+customers[i][1];
            int b=customers[i][0]+customers[i][1];
            sum+=(max(a,b)-customers[i][0]);
            prev=max(a,b);
        }
        return double(sum)/double(customers.size());
    }
};