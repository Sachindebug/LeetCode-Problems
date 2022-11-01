class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        unordered_map<int,vector<int>> ump;
        vector<vector<int>> res;
        for(int i=0;i<arr.size();i++)
        {
            ump[arr[i]].push_back(i);
        }
        for(auto x:ump)
        {
            int n=x.first;
            vector<int> a=x.second;
            vector<int> temp;
            for(int i=0;i<a.size();i++)
            {
                temp.push_back(a[i]);
                if((i+1)%n==0)
                {
                    res.push_back(temp);
                    temp.clear();
                }
            }
            
        }
        return res;
        
    }
};