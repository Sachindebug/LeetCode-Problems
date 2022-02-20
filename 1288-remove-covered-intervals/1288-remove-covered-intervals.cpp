class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals.size()==1) return intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        vector<int> temp=intervals[0];
        for(auto x:intervals)
        {
            if((x[0]>=temp[0] && x[1]<=temp[1]) || (x[0]<=temp[0] && x[1]>=temp[1]))
            {
                count++;
                temp[0]=min(temp[0],x[0]);
                temp[1]=max(temp[1],x[1]);

            }
            else
            {
                temp=x;
            }
        }

        return intervals.size()-count+1;
        
        
    }
};