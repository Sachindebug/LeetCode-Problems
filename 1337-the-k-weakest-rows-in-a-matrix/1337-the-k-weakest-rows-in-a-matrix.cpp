class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<mat.size();i++)
        {
            int x=count(mat[i].begin(),mat[i].end(),1);
            arr.push_back({x,i});
        }
        sort(arr.begin(),arr.end(),myfun);
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(arr[i].second);
        }
        return res;
    }
    static bool myfun(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first<p2.first) return true;
        if(p1.first==p2.first) return p1.second<p2.second;
        return false;
    }
};