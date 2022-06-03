class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        res=recurse(arr,0);
        vector<vector<int>> ans;
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()==k) ans.push_back(res[i]);
        }
        return ans;
    }
    vector<vector<int>> recurse(vector<int> &arr,int idx)
    {
        if(idx==arr.size()) return {{}};
        vector<vector<int>> prev=recurse(arr,idx+1);
        vector<vector<int>> res;
        int x=arr[idx];
        for(int i=0;i<prev.size();i++)
        {
            vector<int> temp=prev[i];
            res.push_back(temp);
            temp.insert(temp.begin(),x);
            res.push_back(temp);
        }
        return res;
    }
};