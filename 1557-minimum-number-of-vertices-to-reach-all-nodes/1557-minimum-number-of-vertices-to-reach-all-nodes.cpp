class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> arr(n);
        for(int i=0;i<edges.size();i++)
        {
            arr[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(!arr[i])
            {
                res.push_back(i);
            }
        }
        return res;
        
    }
};