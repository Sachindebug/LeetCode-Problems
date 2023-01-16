class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.size()==0) 
        {
            res.push_back(newInterval);
            return res;
        }
        if(newInterval[0]<intervals[0][0]) intervals.insert(intervals.begin(),newInterval);
        else if(newInterval[0]>intervals[intervals.size()-1][0]) 
            intervals.insert(intervals.end(),newInterval);
        else
        {
            auto it=upper_bound(intervals.begin(),intervals.end(),newInterval);
            intervals.insert(it,newInterval);
        }

        vector<int> temp=intervals[0];
        for(auto x:intervals)
        {
            if(temp[1]>=x[0])
            {
                temp[1]=max(temp[1],x[1]);
            }
            else
            {
                res.push_back(temp);
                temp=x;
            }
        }
        res.push_back(temp);
        return res;
        
    }
};